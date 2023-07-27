#include <type_traits>


template <typename T>
struct remove_const
{
    using type = T;
};

// specialization to remove type quilifier
template <typename T>
struct remove_const<T const>
{
    using type = T;
};

template <typename T>
struct type_is
{
    using type = T;
};

template <typename T>
struct remove_volatile : type_is<T>{};

template <typename T>
struct remove_volatile<T volatile> : type_is<T> {};

// std::conditional_t<T>
template <bool Cond, typename T, typename>
struct my_conditional : type_is<T> {};

template <typename T, typename F>
struct my_conditional<false, T, F> : type_is<F> {};

/**
 * mimick std::enable_if
 * 
 * default template argument <void> useful. During template instantiation the compiler
 * obtains the template arguments by taking verbatim if explicitly supplied at template's
 * point of use or deduced from function arguments at point of call or taken from the 
 * declaration's default template argument.
 * 
 * The compiler then replaces each template parameter throughout the template, by its
 * corresponding template argument. If these steps produces well formed code, the 
 * instantiation succeeds, but if the corresponfing code is ill-formed, it is considered
 * not viable (due to substitution failure) and is silently discarded. This is the idea
 * behind SFINAE -> Substitution Failure Is Not An Error.
*/
template <bool Cond, typename T = void>
struct my_enable_if : type_is<T>{};

// partial specialization does nothing if condition is false
template <typename T>
struct my_enable_if<false, T> {};

template <typename T, T val>
struct my_integral_constant
{
    static constexpr T value = val;
    constexpr operator() const noexcept { return value; }
    constexpr T operator()() const noexcept { return value; }
};

template <bool B>
using bool_constant = my_integral_constant<bool, B>;

using my_true_type = bool_constant<true>;
using my_false_type = bool_constant<false>;


// int main()
// {

//     // static_assert(remove_const<int const>::type == int);
//     // static_assert(remove_const<const double>::type == int);
//     // std::enable_if_t<int>
// std::is_integral<23>
// }
