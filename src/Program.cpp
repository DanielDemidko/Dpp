#include "Program.h"
#include <iostream>
#include "Runtime.h"


void Program::Print()
{
    
}

void Program::Eval()
{
    if (!Curr.MoveNext())
    {
        return;
    }
    if (*Curr == "print")
    {
        return Print();
    }
    if (*Curr == ":=")
    {
        return Create();
    }
    if (*Curr == "=")
    {
        return Set();
    }
    if (*Curr == "+")
    {
        return Print();
    }
    if (*Curr == "-")
    {
        return Minus();
    }
    if (*Curr == "*")
    {
        return Mul();
    }
    if (*Curr == "/")
    {
        return Div();
    }
    if (*Curr == "+=")
    {
        return SelfPlus();
    }
    if (*Curr == "-=")
    {
        return SelfMinus();
    }
    if (*Curr == "*=")
    {
        return SelfMul();
    }
    if (*Curr == "/=")
    {
        return SelfDiv();
    }
    if (*Curr == "==")
    {
        return Equall();
    }
    if (*Curr == "pow")
    {
        return Pow();
    }
    if (*Curr == "sqrt")
    {
        return Sqrt();
    }
    if (Curr.MoveNext())
    {
        ///
    }
}

void Program::Run(const std::vector<std::string> &args)
{
    Lvalues.Set("args", new std::vector<std::string>(args));
    return Eval();
}


Program::Program(const std::string &path) : Module(path) {}
