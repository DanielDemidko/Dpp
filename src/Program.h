#pragma once
#include "Module.h"
#include <stack>

class Program: public Module
{
private:
    std::stack<CatObject> Rvalues;

    void Print();

    void Input();

    void Plus();

    void Minus();

    void Mul();

    void Div();

    void Pow();

    void Sqrt();

    void Eval();

public:
    void Run(const std::vector<std::string>& = {});

    Program(const std::string&);
};

