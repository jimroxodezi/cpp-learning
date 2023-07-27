// #include <cstdint>
#include <limits.h>
#include <iostream>

template <int N>
struct abs
{
    static_assert(N != INT_MIN);
    static constexpr int value = (N < 0) ? -N : N;
};


int main(void)
{
    static_assert(abs<20>::value == 20);
    static_assert(abs<-20>::value == 20);

    std::cout << INT_MIN << "\n";
}