#include <array>
#include <iostream>


// normal template code.
template <typename T, std::size_t N>
T dot_product(std::array<T,N> const &x, std::array<T,N> const &y) {
    T result{};
    for (std::size_t i; i < N; ++i) {
        result += x[i]*y[i];
    }

    return result;
}


// using template metaprogramming
template <typename T, std::size_t N>
struct DotProduct {
    static inline T result(const T* a, const T* b) {
        return *a * *b + DotProduct<T, N-1>::result(a+1, b+1);
    }
};

// partial template template specialization as end criteria
template <typename T>
struct DotProduct<T, 0> {
    static inline T result(const T*, const T*) {
        return T{};
    }
};

template <typename T, std::size_t N>
auto dot_product_2(std::array<T, N> const &x, std::array<T,N> const &y) {
    return DotProduct<T,N>::result(x.begin(), y.begin());
}

int main(void){
    std::array<int,5> x{1,2,3,4,5}, y{1,2,3,4,5};
    int result1 = dot_product<int,5>(x,y);
    std::size_t result2 = dot_product_2<int,5>(x,y);

    std::cout << "result1: " << result1 << "\n";
    std::cout << "result2: " << result2 << "\n";
}