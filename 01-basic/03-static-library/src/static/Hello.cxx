#include <iostream>
#include "static/Hello.h"

Hello::Hello(/* args */){}

Hello::~Hello(){}

void 
Hello::print()
{
    std::cout << "Hello Static Library!" << std::endl;
}