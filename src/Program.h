#pragma once
#include "Module.h"


struct Program: public Module
{
    void Run(const std::vector<std::string> &args);

    Program(const std::string&);
};

