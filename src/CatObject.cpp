#include "CatObject.h"

double CatObject::ToDouble() const
{
    return ToNum<double>([](const std::string &str)->double { return std::stod(str); });
}

int CatObject::ToInt() const
{
    return ToNum<int>([](const std::string &str)->int { return std::stoi(str); });
}

bool CatObject::ToBool() const
{
    return ToNum<bool>([](const std::string &str)->bool { return str == "true" ? true : false; });
}

char CatObject::ToChar() const
{
    return ToNum<char>([](const std::string &str)->char { return str[0]; });
}

std::string CatObject::ToString() const
{
    if (Memory.Id == CatTypes::String)
    {
        return *this;
    }
    if (Memory.Id == CatTypes::List)
    {
        std::string result;
        for (const CatObject &i : *static_cast<std::shared_ptr<std::vector<CatObject>>&>(*this))
        {
            result += i.ToString() + ' ';
        }
        return result.substr(result.size() - 1);
    }
    return std::to_string(
          Memory.Id == CatTypes::Bool ? static_cast<bool&>(*this)
        : Memory.Id == CatTypes::Char ? static_cast<char&>(*this)
        : Memory.Id == CatTypes::Double ? static_cast<double&>(*this)
        : Memory.Id == CatTypes::Int ? static_cast<int&>(*this)
        : 0
    );
}

std::shared_ptr<std::vector<CatObject>> CatObject::ToList() const
{
    if (Memory.Id == CatTypes::List)
    {
        return *this;
    }
    if (Memory.Id == CatTypes::String)
    {
        std::shared_ptr<std::vector<CatObject>> result(new std::vector<CatObject>);
        for (const char &i : static_cast<std::string&>(*this))
        {
            CatObject tmp = new char(i);
            result->push_back(new char(i));
        }
        return result;
    }
    return std::shared_ptr<std::vector<CatObject>>(new std::vector<CatObject>(ToInt()));
}

CatObject::CatObject() : Object() {}