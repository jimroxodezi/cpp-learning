#include <type_traits>


template <typename T> struct type_is { using type = T; };

template <bool, typename THEN, typename>
struct if_: type_is<THEN>{};

template <typename THEN, typename ELSE>
struct if_ <false, THEN, ELSE> : type_is<ELSE> {};

// type_list<...> is a list of types
// a type_list looks like this: type_list<int, float, bool, double>
template <typename... Types>
struct type_list{};

// check for an empty type_list<...>
// an emtpy list contain nothing. 
template <typename TypeList>
struct is_empty : std::false_type {};

// specailization - pass in an empty type_list<>
template <>
struct is_empty<type_list<>> : std::true_type{};

static_assert(is_empty<type_list<>>::value);
static_assert(is_empty<type_list<float, int, bool>>::value == false);

// front element (the first element) in the list.
template <typename TypeList>
struct front;

template <typename FirstElement, typename... Others>
struct front <type_list<FirstElement, Others...>> {
    using type = FirstElement;
};

static_assert(std::is_same_v<front<type_list<int,float,bool>>::type,int>);
static_assert(std::is_same_v<front<type_list<int,float,bool>>::type,float> == false);

template <typename Typelist>
struct pop_front;

template <typename FirstElement, typename... Others>
struct pop_front<type_list<FirstElement,Others...>>
{
    using type = type_list<Others...>;
};

template <typename TypeList>
using pop_front_t = typename pop_front<TypeList>::type;

template <typename TypeList>
using front_t = typename front<TypeList>::type;

template <typename Typelist>
static constexpr bool is_empty_v = is_empty<Typelist>::value;

/**
 * searches through a type_list<> (TypeList) to look if a type (Search)
 * is present.
*/
template <typename Search, typename Typelist>
struct contains : if_ <
                        is_empty_v<Typelist>,
                        // then
                        std::false_type,
                        // else
                        typename if_ <      // if
                                        std::is_same_v<Search, front_t<Typelist>>,
                                        // then
                                        std::true_type,
                                        // else
                                        contains<Search, pop_front_t<Typelist>>
                                    >::type
                        >::type {};

// specialization to handle the case of an empty type_list<>
template <typename Search>
struct contains<Search, type_list<>> : std::false_type{};

int main()
{
    using list = type_list<int, float, bool>;
    static_assert(contains<int, list>::value);
    return 0;
}