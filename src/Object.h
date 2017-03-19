#pragma once
#include "Typification.h"

// Универсальный обьект, реализует семантику "типов-значений", value-types
class Object
{
protected:
    void *Pointer = nullptr;
    // Обьект для работы с типом
    Typification::Type Memory;

public:
    std::string GetType() const;

    Object &operator=(const Object &);

    Object &operator=(Object &&);

    template <typename T> Object &operator=(T *const pointer)
    {
        Memory.Free(Pointer);
        Pointer = pointer;
        Memory = Typification::GetType<T>();
        return *this;
    }

    bool operator==(const Object&);

    template <typename T> bool operator==(T *const pointer)
    {
        return pointer? Memory.Equall(Pointer, pointer): false;
    }

    // Этот оператор константный, потому что предоставляет доступ только к содержимому указателя, и не дает сменить тип.
    template <typename T> operator T &() const
    {
        return *static_cast<T *>(Pointer);
    }

    template <typename T> Object(T *const pointer) : Pointer(pointer), Memory(Typification::GetType<T>())
    {
    }

    Object(const Object &);

    Object(Object &&);

    Object();

    virtual ~Object();
};