#include <iostream>
#include <type_traits>


template <typename T>
bool equals(T arg1, T arg2, std::enable_if_t<!std::is_floating_point_v<T>>* = nullptr)
{
    return arg1 == arg2;
}

template <typename T>
bool equals(T arg1, T arg2, std::enable_if_t<std::is_floating_point_v<T>>* = nullptr)
{
    return arg1 == arg2;
}

int main(void) {
    equals(1,1);
    return 0;
}