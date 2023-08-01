#include <type_traits>

// identity metafunction...
// canonical type returning function.
template <typename T>
struct type_is { using type = T; };

template <class T>
struct remove_const : type_is<T> {};

// specialization to remove type quilifier
template <typename T>
struct remove_const<T const> : type_is<T> {};

template <typename T>
struct remove_volatile : type_is<T>{};

template <typename T>
struct remove_volatile<T volatile> : type_is<T> {};

// convenience aliases
template <class T> using remove_const_t     = typename remove_const<T>::type;
template <class T> using remove_volatile_t  = typename remove_volatile<T>::type;

template <class T> using remove_cv          = remove_volatile_t<remove_const_t<T>>;
template <class T> using remove_cv_t        = typename remove_cv<T>::type;

/******************************************************************************************************/

// std::conditional_t<T>
template <bool Cond, typename T, typename>
struct my_conditional : type_is<T> {};

template <typename T, typename F>
struct my_conditional<false, T, F> : type_is<F> {};


/*********************************************************************************************************
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

/**
 * C++11 canonical value returning metafunction.
 * Takes the type of the value T and the actual value val
 * as template parameters and returns the value
*/
template <typename T, T val>
struct my_integral_constant
{
    static constexpr T value = val;
    constexpr operator() const noexcept { return value; }
    constexpr T operator()() const noexcept { return value; }
};

using m_true_type = my_integral_constant<bool, true>;
using m_false_type = my_integral_constant<bool, false>;

template <bool B>
using my_bool_constant = my_integral_constant<bool, B>;

// same as above.....
using my_true_type = my_bool_constant<true>;
using my_false_type = my_bool_constant<false>;


int main()
{

    // static_assert(remove_const<int const>::type == int);
    // static_assert(remove_const<const double>::type == int);
    // std::enable_if_t<int>
    // std::is_integral<23>
}
