#include <cstdint>
#include <iostream>

// normal function
uint64_t factorial(uint64_t n) {
    return n == 0 ? 1 : n * factorial(n-1);
}

// using template metaprogramming
template <uint64_t N> struct Factorial {
    static constexpr const uint64_t value = N * Factorial<N-1>::value;
};

// specialized template as end criterion
template<> struct Factorial<0> {
    static constexpr const uint64_t value = 1;
};


int main(void) {
    std::cout << factorial(65) << "\n";

    std::cout << Factorial<65>::value << "\n";
}