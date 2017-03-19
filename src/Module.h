#pragma once
#include "Context.h"
#include "Dq.h"


class Module
{
protected:
    const std::vector<std::string> File;
    Context Stack;
    Dq::Enumerator<std::vector, std::string> Iterator{ File };

public:
    Module(const std::string&);

    virtual ~Module() = default;
};
