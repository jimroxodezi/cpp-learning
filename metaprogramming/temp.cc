#include <cstdlib>
#include <type_traits>
#include <iostream>


template <typename T>
bool equals(const T arg1, const T arg2, std::true_type)
{
    // for float, do some floating point stuff...
    return true;
}

template <typename T>
bool equals(const T arg1, const T arg2, std::false_type)
{
    return arg1 == arg2;
}

// tag dispatch
template <typename T>
bool equals(const T arg1, const T arg2)
{
    return equals<T>(arg1, arg2, std::conditional_t<std::is_floating_point<T>::value, std::true_type, std::false_type>{});
    // same as above
    // return equals<T>(arg1, arg2, typename std::conditional<std::is_floating_point<T>::value, std::true_type, std::false_type>::type{});
}

int main(void)
{
    std::cout << equals(1.f,1.f) <<std::endl;
    std::cout << equals(1,2) << std::endl;
    return EXIT_SUCCESS;
}