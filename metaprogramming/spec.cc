#include <iostream>


// template definition
template <typename KEY, typename VALUE>
struct my_map
{
    my_map(){std::cout << "my_map\n"; }
};

// partial specialization
template <typename VALUE>
struct my_map<int, VALUE>
{
    my_map(){std::cout << "my_map<int, VALUE>\n"; }
};

// full specialization
template <>
struct my_map<int, int>
{
    my_map(){ std::cout << "my_map<int, int>\n"; }
};


int main()
{
    auto default_map = my_map<float,int>{};

    auto partial_specialization = my_map<int, bool>{};

    auto full_specialization = my_map<int, int>{};

}