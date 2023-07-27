#include <string>
#include <type_traits>
#include <cstdint>

template <typename T>
std::enable_if_t<std::is_integral_v<T>, int> f(T val) {}


template <typename T>
std::enable_if_t<std::is_floating_point_v<T>, long double> f(T val) {}

int main(void) {
    // f(std::string{"hey"});
    // f(42.3);
}