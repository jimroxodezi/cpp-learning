#include <type_traits>


template <typename T>
struct is_void : std::false_type {};

// specializations to handle different void types
template <> struct is_void<void> : std::true_type {};
template <> struct is_void<const void> : std::true_type {};
// template <> struct is_void<void> : std::true_type {};
// template <> struct is_void<void> : std::true_type {};

// convenience alias
template <class T>
constexpr bool is_void_v = is_void<T>::value;

static_assert(is_void_v<const void>);

// primary template for distinct types
template <class T, class U> struct is_same : std::false_type {};

// specialization to handle same types
template <class T> struct is_same<T, T> : std::true_type {};

// convenience alias
template <class T, class U> constexpr bool is_same_v = is_same<T,U>::value;

static_assert(is_same_v<int,int>);

// endless possiblities with type aliasing and metafunction delegation
template <class T>
using a_is_void = is_same_v<std::remove_cv_t<T>, void>;