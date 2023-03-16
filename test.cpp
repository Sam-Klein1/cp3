#include "ZLL.h"
#include <iostream>
int main()
{

    ZLL<int> myzll1;
    myzll1.back(1);
    myzll1.back(2);
    myzll1.back(3);

    ZLL<int> myzll2;
    myzll2.back(1);
    myzll2.back(3);
    myzll2.back(6);

    myzll1 -= myzll2;


}