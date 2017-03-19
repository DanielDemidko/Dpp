#include "Program.h"
#include <iostream>


void Program::Run(const std::vector<std::string> &args)
{
    Stack.Set("args", new std::vector<std::string>(args));
    
}


Program::Program(const std::string &path) : Module(path) {}
