#include <type_traits>

/**********************************************************************************/
template <typename T>
struct is_void : std::false_type {};

// specializations to handle different void types
template <> struct is_void<void> : std::true_type {};
template <> struct is_void<void const> : std::true_type {};
template <> struct is_void<void volatile> : std::true_type {};
template <> struct is_void<void const volatile> : std::true_type {};

// convenience alias
template <class T>
constexpr bool is_void_v = is_void<T>::value;

static_assert(is_void_v<const void>);


/***************************************************************************************/
// primary template for distinct types
template <class T, class U> struct is_same : std::false_type {};

// specialization to handle same types
template <class T> struct is_same<T, T> : std::true_type {};

// convenience alias
template <class T, class U> constexpr bool is_same_v = is_same<T,U>::value;

static_assert(is_same_v<int,int>);

// endless possiblities with type aliasing and metafunction delegation
template <class T> using a_is_void            = is_same_v<std::remove_cv_t<T>, void>;
template <class T> constexpr bool a_is_void_v = a_is_void<T>::value;

/***********************************************************************************************/
// check if a type T is in a parameter pack T0toN...
template <class T, class ... T0toN>
struct is_one_of;

// specialization for empty list
template <class T>
struct is_one_of<T> : std::false_type {};

// specialization for match at beginning of list
template <class T, class... T0toN>
struct is_one_of<T,T, T0toN...> : std::true_type {};

// specialization for mismatch at beginning of list. Throw ListHead away
// and reccursively "traverse" through list till a match is found or not
// found for an empty list and return false.
template <class T, class ListHead, class... RestElements>
struct is_one_of<T, ListHead, RestElements...> : is_one_of<T,RestElements...> {};

// another implementation of is_void using metafunction delegation
template <class T> using b_is_void = is_one_of<T
                                                ,void
                                                ,void const
                                                ,void volatile
                                                ,void volatile const
                                                ,>;

// std::__type_identity<int>;

// is_pointer

namespace detail   
{

template <class T> struct is_pointer_impl : std::false_type {};
template <class T> struct is_pointer_impl<T*> : std::true_type {};

} // namespace detail

template <class T> using is_pointer = detail::is_pointer_impl<std::remove_cv_t<T>>;

// void_t
template <typename...>
using void_t = void;