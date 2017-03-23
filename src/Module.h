#pragma once
#include "Context.h"
#include "Dq.h"


class Module
{
private:
    const std::vector<std::string> File;

public:
    Context Lvalues;
    Dq::Enumerator<std::vector, std::string> Curr{ File };

    Module(const std::string&);

    virtual ~Module() = default;
};
