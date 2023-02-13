#include <iostream>
#include <concepts>

template <typename T>
concept supports_less_than = requires (T x) {x < x; };

template <typename T>
requires std::copyable<T> && supports_less_than<T>
T mymax(T a, T b) {
    return a > b ? a : b;
}


int main(void) {
    std::cout << mymax(12,4) << std::endl;

    return 0;
}