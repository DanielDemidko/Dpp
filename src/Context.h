#pragma once
#include <vector>
#include "CatObject.h"

class Context
{
private:
    std::vector<std::pair<std::string, CatObject>> Stack;
    std::vector<std::vector<std::pair<std::string, CatObject>>::iterator> Scopes;

public:
    void Set(const std::string&, CatObject);

    CatObject &Get(const std::string&);

    void New(const std::string&, CatObject);

    void End();
};