#pragma once
#include "Object.h"
#include <vector>
#include <memory>
#include "CatTypes.h"

class CatObject : public Object
{
private:
    template<typename T> T ToNum(const std::function<T(const std::string&)> &cast) const
    {
        return Memory.Id == CatTypes::Bool? static_cast<bool&>(*this)
             : Memory.Id == CatTypes::Char? static_cast<char&>(*this)
             : Memory.Id == CatTypes::Double? static_cast<double&>(*this)
             : Memory.Id == CatTypes::Int? static_cast<int&>(*this)
             : Memory.Id == CatTypes::List? static_cast<std::shared_ptr<std::vector<CatObject>>&>(*this)->size()
             : Memory.Id == CatTypes::String? cast(static_cast<std::string&>(*this))
             : T();
    }

public:
    double ToDouble() const;

    int ToInt() const;

    bool ToBool() const;

    char ToChar() const;

    std::string ToString() const;

    std::shared_ptr<std::vector<CatObject>> ToList() const;

    template<typename T> CatObject(T *const pointer) : Object(pointer)
    {
    }

    CatObject();
};
