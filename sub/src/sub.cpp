#include "sub.h"
#include <iostream>
int sub(int a, int b)
{
    std::cout << "sub(" << a << ", " << b << ") called" << std::endl;
    return a - b;
}