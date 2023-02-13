#include <concepts>
#include <iostream>

// cpp20 concepts provide constraints on template params
// compile with -std=c++20 flag

// concepts evaluates to bool?
template <typename T>
concept Number = std::is_same_v<T, int> || std::is_floating_point_v<T>;

// template <Number Num>
// Num sum(Num a, Num b) {
//     return a + b;
// }

// same as above
auto sum(Number auto a, Number auto b) {
    return a + b;
}

int main(void) {
    std::cout << sum(12,42) << std::endl;
}