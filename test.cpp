#include "ZLL.h"
#include <iostream>
#include <string>
int main()
{

    ZLL<int> list1;
    ZLL<int> list2;

    std::cout << "==================1===========================" << std::endl;
    list1.join(list2); //both are empty
    list1.print();
    std::cout << "==================2===========================" << std::endl;
    list2.back(4); //this is empty 
    list2.front(6);
    list2.front(5);
    list2.print();
    list1.join(list2);
    list1.print();

    std::cout << "==================3===========================" << std::endl;
    list1.front(1);
    list1.front(2);
    list1.front(3);
    list2.back(4); 
    list2.front(6);
    list2.front(5);
    list1.print();
    list2.print();
    list1.join(list2);
    list1.print();
        

}