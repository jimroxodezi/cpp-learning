#include <iostream>
#include <string>
#include <type_traits>

template <typename T>
struct my_is_pointer
{
    static constexpr bool value = false;
};

template <typename T>
struct my_is_pointer<T*>
{
    static constexpr bool value = true;
};

template <typename T>
struct remove_pointer
{
    using type = T;
};

template <typename T>
struct remove_pointer<T*>
{
    using type = T;
};

template <typename T>
static constexpr bool my_is_pointer_v = my_is_pointer<T>::value;

template <typename T>
using remove_pointer_t = typename remove_pointer<T>::type;

template <typename T>
void print1(T t) {
    // using T_without_pointer = remove_pointer<T>::type;
    if constexpr(my_is_pointer_v<T> && (std::is_floating_point_v<remove_pointer_t<T>>)) {
        std::cout << *t;
    } else {
        std::cout << t;
    }
}

template <typename A, typename B, typename C>
void print3(A a, B b, C c) {
    print1(a);
    std::cout << ",";
    print1(b);
    std::cout << ",";
    print1(c);
    std::cout << "\n";
}


int main()
{
    std::cout << "===========================template metaprogramming===================================\n";
    // print(1,2,3);
    float a = 10;
    double b = 2;
    std::string s = "hmmmm";
    print3(&a, &b, s);

}