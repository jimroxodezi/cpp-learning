#include <cstdlib>


template <typename T>
struct rank
{
    static constexpr std::size_t value = 0;
};

template <typename T>
struct rank<T[]>
{
    static constexpr std::size_t value = 1u + rank<T>::value;
};

template <typename T, std::size_t N>
struct rank<T[N]>
{
    static constexpr std::size_t value = 1u + rank<T>::value;
};

int main()
{
    static_assert(rank<int[]>::value == 1);
    int x = rank<int[][2][3]>::value;
}