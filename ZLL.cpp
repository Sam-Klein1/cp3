#include <iostream>
#include "zany.h"

template <typename T> Node<T>::Node(const T &thing){

    next = nullptr;
    prev = nullptr;
    item = thing;
}
template <typename T> ZLL<T>::ZLL(){


    head = nullptr;
    tail = nullptr;
    ptr = nullptr;

}
template <typename T> ZLL<T>::~ZLL(){

    Node<T> *curr = head;
    while(curr){
        Node<T> *NodeToDelete = curr;
        curr = curr->next;
        delete NodeToDelete;
    }
    head = nullptr;
    tail = nullptr;
}
template <typename T> bool ZLL<T>::front(const T &item){ /* Tested */

    Node<T> *nn = new Node<T>(item);
    if(head == nullptr){
        head = nn;
        tail = nn;
        return true;
    }
    else{
        nn->next = head;
        nn->prev = nullptr; //since this should be the first
        head->prev = nn;
        head = nn;
        return true;
    }
    return false; 

}
template <typename T> bool ZLL<T>::back(const T &item){ /* Tested */

    Node<T> *nn = new Node<T>(item);
    if(tail == nullptr){
        tail = nn;
        head = nn;
        return true;
    }
    else{
        nn->prev = tail;
        nn->next = nullptr; //since this should be the last node
        tail->next = nn;
        tail = nn;
        return true;
    }
    return false;

}
template <typename T> bool ZLL<T>::join(ZLL<T> &other){ /*Tested*/

        if(other.isEmpty() && this->isEmpty()){ //just return true
        return true;
    }
    else if(other.isEmpty()){ //just return true
        return true;
    }
    else if(this->isEmpty()){ //copy head and tail over
        head = other.head;
        tail = other.tail;
        other.head = nullptr;
        other.tail = nullptr;
        return true;
    }
    else if(this != &other){
        tail->next = other.head;
        other.head->prev = tail;
        tail = other.tail;
        other.head = nullptr;
        other.tail = nullptr;
        return true;
    }
    else
        return true;


    /*
    // If the other list is empty, just return true.
    if (other.head == NULL)
    {
        return true;
    }

    // If the other list is the same as this one, do nothing and return true.
    if (&other == this)
    {
        return true;
    }

    // Join the other list onto the end of this one.
    if (tail != NULL)
    {
        tail->next = other.head;
        other.head->prev = tail;
        tail = other.tail;
    }
    else
    {
        head = other.head;
        tail = other.tail;
    }

    // Clear the other list.
    other.head = NULL;
    other.tail = NULL;

    // other.empty();

    return true;
}
*/
    

}
template <typename T> ZLL<T> &ZLL<T>::operator+=(const ZLL<T> &other){ /*Tested*/

    if(this == &other) return *this;
    else{
        
        Node<T> *curr = other.head;
        while(curr){

            this->back(curr->item);
            curr = curr->next;
        }
        return *this;

    }
}
template <typename T> ZLL<T> &ZLL<T>::operator-=(const ZLL<T> &other){ /*Tested*/

    if(this == &other) return *this;
    else{

        T searchItem;
        Node<T> *currOther = other.head;
        Node<T> *curr = nullptr;
        while(currOther){
            
            searchItem = currOther->item;
            curr = head;
            while(curr){
                if(curr->item == searchItem){
                    Node<T> *NodeToDelete = curr; //save node
                    curr = curr->next; //advance curr
                    if (NodeToDelete == head) //deleted from the front
                        head = curr;
                    else if (NodeToDelete == tail){ //deleted from the back
                        tail = NodeToDelete->prev;
                        tail->next = nullptr;
                    }
                    else{ //anywhere else, need prev and suc node
                        Node<T> *previous = NodeToDelete->prev;
                        Node<T> *suc = NodeToDelete->next;
                        previous->next = NodeToDelete->next;
                        suc->prev = NodeToDelete->prev;
                    }
                    delete NodeToDelete;
                }
                else{
                    curr = curr->next;
                }
            }
        currOther = currOther->next;
        }
    }
    return *this;
}
template <typename T> int ZLL<T>::removeZany()
{
    int count = 0;
    Node<T> *curr = head;
    while (curr)
    {
        if (isZany(curr->item)){
            Node<T> *NodeToDelete = curr; //save node
            curr = curr->next; //advance curr
            if (NodeToDelete == head) //deleted from the front
                head = curr;
            else if (NodeToDelete == tail){ //deleted from the back
                tail = NodeToDelete->prev;
                tail->next = nullptr;
            }
            else{ //anywhere else, need prev and suc node
                Node<T> *previous = NodeToDelete->prev;
                Node<T> *suc = NodeToDelete->next;
                previous->next = NodeToDelete->next;
                suc->prev = NodeToDelete->prev;
            }
            delete NodeToDelete;
            count++;
        }
        else
            curr = curr->next;
    }
    return count;
}
template <typename T> int ZLL<T>::removeNonZany() //basically same as remove zany
{
    int count = 0;
    Node<T> *curr = head;
    while (curr)
    {
        if (!isZany(curr->item))
        {
            Node<T> *NodeToDelete = curr;
            curr = curr->next;
            if (NodeToDelete == head)
                head = curr;

            else if (NodeToDelete == tail){
                tail = NodeToDelete->prev;
                tail->next = nullptr;
            }
            else{
                Node<T> *previous = NodeToDelete->prev;
                Node<T> *suc = NodeToDelete->next;
                previous->next = NodeToDelete->next;
                suc->prev = NodeToDelete->prev;
            }
            delete NodeToDelete;
            count++;
        }
        else
            curr = curr->next;
    }
    return count;
}
template <typename T> bool ZLL<T>::isEmpty(){
    if(head == nullptr)
        return true;
    else 
        return false;
}
template <typename T> bool ZLL<T>::empty(){
    Node<T> *curr = head;
    while(curr){
        Node<T> *NodeToDelete = curr;
        curr = curr->next;
        delete NodeToDelete;
    }
    head = nullptr;
    tail = nullptr;
    return true;
}
template <typename T> bool ZLL<T>::promoteZany(){ /*Tested*/

    Node<T> *curr = head;
    Node<T> *promote = nullptr;
    while(curr){

        if(isZany(curr->item)){
            promote = curr; //node to promote
            curr = curr->next;
            if (promote == head) //deleted from the front
                continue;
            else if (promote == tail){ //deleted from the back
                tail = promote->prev;
                tail->next = nullptr;
                front(promote->item);
                delete promote;
            }
            else{ //anywhere else, need prev and suc node
                Node<T> *previous = promote->prev;
                Node<T> *suc = promote->next;
                previous->next = promote->next;
                suc->prev = promote->prev;
                front(promote->item);
                delete promote;
            }
        }
        else{
            curr = curr->next;
        }
    }
    return true;
}
template <typename T> bool ZLL<T>::start(){ /*Tested*/

    if(head && tail){
        ptr = head;
        return true;
    }
    else{
        return false;
    }
}
template <typename T> bool ZLL<T>::done(){ /*Tested*/

    if(ptr) {return false;} else {return true;}

}
template <typename T> T ZLL<T>::getNext(){ /*Tested*/
    
    T ret = ptr->item;
    ptr = ptr->next;

    return ret;
}
template <typename T> void ZLL<T>::print(){ /*Tested*/

    Node<T> *saveHead = head; //save starting point 
    while(head != nullptr){
        std::cout << head->item << " ";
        head = head->next;
    }
    std::cout << std::endl;
    head = saveHead; //point head back to beginning 
}
