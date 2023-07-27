#include <iostream>


template <int val>
struct report
{
    static constexpr int value = val;
};

template <int...>
struct scan;

template <int count, int a>
struct scan<count, a>
{
    static constexpr inline int value = count;
};

template<int count, int a, int b,int... rest>
struct scan<count, a, b, rest...> : scan<count + (a<b), b,rest...> {};

// template<int count, int a, int b, int... rest>
// struct scan<count,a,b,rest...>
// {
//     static constexpr int value;
//     constexpr if(a<b) {
//         value = count + 1;
//     }
// };

int main()
{
    int res = report<scan<0,2,3,4,5,6,7>::value>::value;
    std::cout << res << std::endl;

}
