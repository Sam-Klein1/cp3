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
        tail->next = nn;
        tail = nn;
        return true;
    }
    return false;

}
template <typename T> bool ZLL<T>::join(ZLL &other){ /*Tested*/

    if(this != &other){
        tail->next = other.head;
        other.head->prev = tail;
        tail = nullptr;
        tail = other.tail;
        other.head = nullptr;
        return true;
    }
    else{
        return false;
    }

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
        Node<T> *NodeToDelete = nullptr;
        Node<T> *currOther = other.head;
        Node<T> *curr = nullptr;
        while(currOther){
            
            searchItem = currOther->item;
            curr = head;
            while(curr){
                if(curr->item == searchItem){
                    if(curr->prev == nullptr){//were removing from beginning
                        NodeToDelete = curr;
                        head = head->next; //move head over one
                        head->prev = nullptr; //head->prev should always point to null
                        curr = head; //set current node = head again
                    }
                    else if(curr->next == nullptr){//were removing from the end
                        NodeToDelete = curr;
                        tail = tail->prev; //move tail left one 
                        tail->next = nullptr; //tail->next should always point to null
                        curr = tail; 
                    }
                    else{
                        Node<T> *previous = curr->prev;
                        Node<T> *suc = curr->next;
                        previous->next = curr->next;
                        suc->prev = previous;
                        NodeToDelete = curr;
                        curr = curr->next;
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
template <typename T> int ZLL<T>::removeZany(){ /*Tested*/

    Node<T> *NodeToDelete = nullptr;
    Node<T> *curr = head;
    int count = 0;
    while(curr){
        if(isZany(curr->item)){
            if(curr->prev == nullptr){//were removing from beginning
                NodeToDelete = curr;
                head = head->next; //move head over one
                head->prev = nullptr; //head->prev should always point to null
                curr = head; //set current node = head again
                delete NodeToDelete; 
            }
            else if(curr->next == nullptr){//were removing from the end
                NodeToDelete = curr;
                tail = tail->prev; //move tail left one 
                tail->next = nullptr; //tail->next should always point to null
                curr = tail; 
                delete NodeToDelete;
            }
            else{
                Node<T> *previous = curr->prev;
                Node<T> *suc = curr->next;
                previous->next = curr->next;
                suc->prev = previous;
                NodeToDelete = curr;
                curr = curr->next;
                delete NodeToDelete;
            }
            count++;
        }
        else
            curr = curr->next;
    }
    return count;
}
template <typename T> int ZLL<T>::removeNonZany(){ /*Tested*/

    Node<T> *NodeToDelete = nullptr;
    Node<T> *curr = head;
    int count = 0;
    while(curr){
        if(!isZany(curr->item)){
            if(curr->prev == nullptr){//were removing from beginning
                NodeToDelete = curr;
                head = head->next; //move head over one
                head->prev = nullptr; //head->prev should always point to null
                curr = head; //set current node = head again
                delete NodeToDelete; 
            }
            else if(curr->next == nullptr){//were removing from the end
                NodeToDelete = curr;
                tail = tail->prev; //move tail left one 
                tail->next = nullptr; //tail->next should always point to null
                curr = tail; 
                delete NodeToDelete;
            }
            else{
                Node<T> *previous = curr->prev;
                Node<T> *suc = curr->next;
                previous->next = curr->next;
                suc->prev = previous;
                NodeToDelete = curr;
                curr = curr->next;
                delete NodeToDelete;
            }
            count++;
        }
        else
            curr = curr->next;
    }
    return count;
}
template <typename T> bool ZLL<T>::promoteZany(){ /*Tested*/

    Node<T> *curr = head;
    Node<T> *NodeToMove = nullptr;
    while(curr){

        if(isZany(curr->item)){
            if(curr->prev == nullptr){//were removing from beginning dont need to do anything
                curr = curr->next;
            }
            else if(curr->next == nullptr){//were removing from the end
                NodeToMove = curr;
                tail = tail->prev; //move tail left one 
                tail->next = nullptr; //tail->next should always point to null
                curr = tail; 
                front(NodeToMove->item); //move to front, this makes a new node but its okay because we delete the old one
                delete NodeToMove;
            }
            else{
                Node<T> *previous = curr->prev;
                Node<T> *suc = curr->next;
                previous->next = curr->next;
                suc->prev = previous;
                NodeToMove = curr;
                curr = curr->next;
                front(NodeToMove->item); //move to front, this makes a new node but its okay because we delete the old one
                delete NodeToMove;
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
