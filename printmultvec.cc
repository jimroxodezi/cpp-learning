#include <iostream>
#include <vector>
#include <algorithm>

 void print_vector(const std::vector<int> vec) {
    for (std::vector<int>::const_iterator cit = vec.cbegin(); cit != vec.cend(); ++cit)
        std::cout << *cit << " ";
    std::cout << "\n";
 }

 int main(){
    auto v1 = std::vector(9,0);
    auto v2 = std::vector{1,2,3,4,5,6,7,8,9};
    auto v3 = std::vector{1,2,3,4,5,6,7,8,9};
    auto v4 = std::vector{1,2,3,4,5,6,7,3,2};
    auto v5 = std::vector{1,2,3,4,5,6,7,1,3};
    auto v6 = std::vector{1,2,3,4,5,6,7,4,6};
    auto v7 = std::vector{1,2,3,4,5,6,7,5,6};
    auto v8 = std::vector{1,2,3,4,5,6,7,9,4};
    auto v9 = std::vector(9,0);

    std::vector<std::vector<int>> vec2d {v1,v2,v3,v4,v5,v6,v7,v8,v9};

    std::for_each(vec2d.cbegin(), vec2d.cend(), print_vector);
 }