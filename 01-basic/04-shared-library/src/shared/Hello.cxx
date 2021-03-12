#include <iostream>
#include "shared/Hello.h"

Hello::Hello(/* args */){}

Hello::~Hello(){}

void 
Hello::print()
{
    std::cout << "Hello Shared Library!" << std::endl;
}