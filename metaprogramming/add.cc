#include <iostream>

template <int X, int Y>
struct add {
    static constexpr inline int value = X + Y;
};

int main(void) {
    const int a = 10, b = 20;
    constexpr int result = add<a,b>::value;

    std::cout << result << "\n";
    return 0;
}