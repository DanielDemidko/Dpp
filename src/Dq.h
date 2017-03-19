#pragma once

namespace Dq
{
    template <template <typename...> typename Container, typename ...Args>
    class Enumerator
    {
    private:
        const Container<Args...> &List = Container<Args...>();
        typename Container<Args...>::const_iterator Position = List.cbegin() - 1;

    public:
        bool MoveNext()
        {
            return ++Position != List.cend();
        }

        const typename Container<Args...>::value_type &operator*() const
        {
            return *Position;
        }

        void Reset()
        {
            Position = List.cbegin() - 1;
        }

        Enumerator(const Container<Args...> &cont) : List(cont)
        {
        }
    };


    template <template <typename...> typename Container, typename ...Args>
    Enumerator<Container, Args...> GetEnumerator(const Container<Args...> &cont)
    {
        return Enumerator<Container, Args...>(cont);
    }


    template<typename T> 
    std::vector<T> Range(T first, const T &last)
    {
        std::vector<T> result;
        for (; first != last; ++first)
        {
            result.push_back(first);
        }
        return result;
    }
}
