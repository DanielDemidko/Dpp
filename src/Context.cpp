#include "Context.h"
#include <algorithm>
#include "Runtime.h"

void Context::Set(const std::string &name, CatObject obj)
{
    Stack.push_back({ name, std::move(obj) });
}

CatObject &Context::Get(const std::string &name)
{
    const auto fix = std::find_if(Stack.rbegin(), Stack.rend(), [&name](const auto &i) { return i.first == name; });
    if (fix == Stack.rend())
    {
        Runtime::Exception("<Error: Variable '" + name + "' was not found>\n");
    }
    return fix->second;
}

void Context::New(const std::string &name, CatObject obj)
{
    Set(name, std::move(obj));
    Scopes.push_back(Stack.end() - 1);
}

void Context::End()
{
    if (Scopes.empty())
    {
        Runtime::Exception("Uncorrect end of scopes");
    }
    Stack.erase(Scopes.back(), Stack.end());
    Scopes.erase(Scopes.end() - 1);
}