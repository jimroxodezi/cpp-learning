#include <iostream>

template <int X, int Y>
struct pow
{
    static constexpr inline const long long value = 2 * pow<X, Y-1>::value;
};

// terminating specialization
template <int X> struct pow<X, 0> {
    static constexpr inline const long long value = 1;
};


int main(void) {
    std::cout << pow<2,60>::value << std::endl;
}

