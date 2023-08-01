#include <cstdlib>
#include <type_traits>

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

// simplified version of std::integral_constant<T, T val>
template <typename T, T val>
struct m_integral_constant
{
    static constexpr T value = val;
    // other member functions....
};

/**
 * Another way to implement rank...by inheriting from the standard 
 * library canonical value returning metafunction std::integral_constant<typename T, T val>
*/
template <typename T>
struct rank_ : m_integral_constant<size_t, 0u> {};

template <typename T, size_t N>
struct rank_<T[N]> : 
    m_integral_constant<size_t, 1u + rank_<T>::value> {};

template <typename T>
struct rank_<T[]> :
    m_integral_constant<size_t, 1u + rank_<T>::value> {};


int main()
{
    static_assert(rank<int[]>::value == 1);
    static_assert(rank<int[2]>::value == 1);
    static_assert(rank_<int[]>::value == 1);
    static_assert(rank_<int[2][3]>::value == 2);
    int x = rank<int[][2][3]>::value;
}