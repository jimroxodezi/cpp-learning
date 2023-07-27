#include <iostream>
#include <vector>

// template <typename It>
// bool contains(It first, It last, bool (*pred)(typename It::value_type const &))
// {
//     for (; first != last; first++){
//         if (pred(*first)) {
//             return true;
//         }
//     }

//     return false;
// }

// to make the above function work for any type of predicate
// // we allow the compiler to do the work--type deduction
template <typename It, typename Pred>
bool contains(It first, It last, Pred pred)
{
    for (; first != last; first++){
        if (pred(*first)) {
            return true;
        }
    }
    return false;
}


bool hasATwo(int const& i)
{
    return i == 2;
}

struct s{
    decltype(auto) operator()(int const & i) const { return i == 2;}
};

int main(void)
{
    std::vector<int> v = {1,2,3,4,5};
    std::cout << contains(v.begin(), v.end(), hasATwo) << std::endl;
    std::cout << contains(v.begin(), v.end(), [](int const& i) {return i == 2;}) << std::endl;
    std::cout << contains(v.begin(), v.end(), s()) << std::endl;
}