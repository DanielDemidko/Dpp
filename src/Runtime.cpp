#include "Runtime.h"
#include <iostream>


void Runtime::Exception(const std::string &error)
{
    std::cerr << error << '\n';
    std::exit(1);
}


