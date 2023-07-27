


template <unsigned int A, unsigned int B>
struct gcd
{
    static inline constexpr int value = gcd<A, A%B>::value;
};

template <unsigned int A>
struct gcd<A,0>
{
    static_assert(A != 0);
    static inline constexpr int value = A;
};

int main(){
    static_assert(gcd<5,15>::value == 5);
}