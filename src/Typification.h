#pragma once
#include <functional>

namespace Typification
{
    // Универсальный тип
    struct Type
    {
        std::string Id;
        std::function<void(void*)> Free;
        std::function<void*(void*)> Copy;
        std::function<bool(void*, void*)> Equall;
    };

    // Шаблонная функция возвращает тип
    template <typename T> Type GetType()
    {
        return
        {
            typeid(T).name(),
            [](void *pointer) -> void { delete static_cast<T*>(pointer); },
            [](void *pointer) -> void* { return new T(*static_cast<T *>(pointer)); },
            [](void *a, void *b) -> bool { return *static_cast<T *>(a) == *static_cast<T *>(b); }
        };
    }
}
