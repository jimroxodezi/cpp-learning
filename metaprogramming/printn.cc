#include <type_traits>
#include <iostream>
#include <utility>
#include <tuple>

void printn(){
    std::cout << "\n";
}

template <typename T>
void printn(T &&t)
{
    std::cout << std::forward<T>(t) << "\n";
}

template <typename T, typename ... Ts>
void printn(T &&t, Ts&& ... rest)
{
    std::cout << std::forward<T>(t) << ", ";
    printn(std::forward<Ts>(rest)...);   
}

template <typename TUPLE, size_t... indices>
void print_tuple_impl(TUPLE &&t, std::index_sequence<indices...>){
    printn(std::get<indices>(std::forward<TUPLE>(t))...);
}

template <typename TUPLE>
void print_tuple(TUPLE &&t) {
    print_tuple_impl(std::forward<TUPLE>(t), 
                    std::make_index_sequence<std::tuple_size<std::remove_reference_t<TUPLE>>::value>{});
}

int main() {
    std::cout << std::boolalpha;

    auto tp = std::make_tuple(9, "hello", 1.5, true);
    print_tuple(tp);
}