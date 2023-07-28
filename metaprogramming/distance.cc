#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <string>
#include <iostream>
#include <iterator>

// mimicking std::is_same<T,U>
template <typename T, typename U>
struct m_is_same {
    static constexpr bool value = false;
};

// specialization for same type.
template <typename T>
struct m_is_same<T,T> {
    static constexpr bool value = true;
};

// convenience function...
template <typename T, typename U>
constexpr bool m_is_same_v = m_is_same<T,U>::value;

// distance between two iterators of the same type
// template <typename It>
// size_t _distance(It first, It last){
//     // doesn't work for non random_access iterators
//     return last - first;
// }

// // this works but inefficient for random access iterator
// // since we have to traverse from first to last instead of 
// // a simple lookup.
// template <typename It>
// size_t _distance(It first, It last)
// {
//     size_t result = 0;
//     for (; first != last; first++) result++;

//     return result;
// }

template <typename It>
size_t _distance(It first, It last)
{
    // check if iterator is random access at compile time
    using category = typename std::iterator_traits<It>::iterator_category;
    // if constexpr(std::is_same_v<std::random_access_iterator_tag, category>) {
    // // use custom type_trait
    if constexpr(m_is_same_v<std::random_access_iterator_tag, category>) {
        return last - first;
    } else {
        size_t result = 0;
        for (; first != last; first++) result++;

        return result;
    }
}

int main()
{
    // // random access iterator
    // std::vector<std::string> names{"Anna", "Ethan", "Nikhil", "Avery"};
    // std::deque<std::string> names{"Anna", "Ethan", "Nikhil", "Avery"};
    // std::set<T> uses bidirectional iterator -- doesn't work!
    std::set<std::string> names{"Anna", "Ethan", "Nikhil", "Avery"};

    auto iter_anna = std::find(names.begin(), names.end(), "Anna");
    auto iter_avery = std::find(names.begin(), names.end(), "Avery");

    std::cout << _distance(iter_anna, iter_avery) << "\n";
}