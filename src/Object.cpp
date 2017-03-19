#include "Object.h"

std::string Object::GetType() const
{
    return Memory.Id;
}

bool Object::operator==(const Object &other)
{
    return Memory.Equall(Pointer, other.Pointer);
}

Object &Object::operator=(const Object &other)
{
    Memory.Free(Pointer);
    Pointer = (Memory = other.Memory).Copy(other.Pointer);
    return *this;
}

Object &Object::operator=(Object &&other)
{
    Memory.Free(Pointer);
    Memory = other.Memory;
    Pointer = other.Pointer;
    other.Pointer = nullptr;
    return *this;
}

Object::Object(const Object &other) : Memory(other.Memory), Pointer(other.Memory.Copy(other.Pointer))
{
}

Object::Object(Object &&other) : Memory(other.Memory), Pointer(other.Pointer)
{
    other.Pointer = nullptr;
}

Object::Object() : Pointer(nullptr), Memory(Typification::GetType<nullptr_t>()) {}

Object::~Object()
{
    Memory.Free(Pointer);
}