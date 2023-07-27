#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <type_traits>



// type_is is more like a universal trait.
template <typename T>
struct type_is { using type = T; };

template <bool, typename THEN, typename>
struct if_ : type_is<THEN> {};

template <typename THEN, typename ELSE>
struct if_<false, THEN, ELSE> : type_is<ELSE> {};

// // same as above
// template <bool Cond, typename THEN, typename ELSE>
// struct if_;

// template <typename THEN, typename ELSE>
// struct if_<true, THEN, ELSE> { using type = ELSE; };

// template <typename THEN, typename ELSE>
// struct if_<false, THEN, ELSE> { using type = THEN; };

// // template <bool,typename T, typename F>
// // static constexpr bool if_v = if_<true,T, F>;

// bool contains(const std::string& search, const std::vector<std::string>& vec, size_t start_from = 0)
// {
//     if (vec[start_from] == search) {
//         return true;
//     } else {
//         if (start_from == vec.size() - 1) {
//             return false;
//         } else {
//             return contains(search, vec, start_from+1);
//         }
//     }
// }

// mimicking the above algorithm
/**
 * contains_type "searches" through a tuple type TUPLE looking for 
 * a type SEARCH if it's in the tuple, starting at the 0th index
*/
template <typename SEARCH, typename TUPLE, size_t start_from = 0>
struct contains_type :
    if_<
        std::is_same_v<std::tuple_element_t<start_from, TUPLE>, SEARCH>,
        // THEN
        typename std::true_type,
        // ELSE
        typename if_ <
            (start_from == std::tuple_size_v<TUPLE> - 1),
            typename std::false_type,
            // ELSE
            contains_type<SEARCH, TUPLE, start_from+1u>
        >::type
    >::type
{};

// partial specialization to handle the case of an empty tuple
template <typename SEARCH>
struct contains_type<SEARCH, std::tuple<>, 0> : std::false_type {};

// // using standard library typetrait std::conditional_t<...>
// template <typename SEARCH, typename TUPLE, size_t start_from = 0>
// struct contains_type :
//     std::conditional_t<
//         std::is_same<typename std::tuple_element<start_from, TUPLE>::type, SEARCH>::value,
//         // THEN
//         std::true_type,
//         // ELSE
//         typename std::conditional_t <
//             (start_from == std::tuple_size<TUPLE>::value - 1),
//             std::false_type,
//             // ELSE
//             contains_type<SEARCH, TUPLE, start_from+1>
//         >
//     >
// {};

int main(){
    // std::vector<std::string> vec{"int", "bool", "float"};
    // std::cout << std::boolalpha << contains("bool", vec) << "\n";

    // std::cout << std::boolalpha << std::is_same_v<int, if_<(10<5), int, float>::type> << "\n";

    std::tuple<int, float, double, std::string> t;
    // std::cout << std::boolalpha << contains_type<int, std::tuple<int, float, std::string>>::value << "\n";
    // std::cout << std::boolalpha << contains_type<int, decltype(t)>::value << "\n";

    static_assert(contains_type<float, std::tuple<int, float, double, std::string>>::value == true);
    static_assert(contains_type<int, decltype(t)>::value == true);

    // std::cout << std::boolalpha << std::true_type::value << "\n";
}