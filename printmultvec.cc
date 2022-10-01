#include <iostream>
#include <vector>
#include <algorithm>

 void print_vector(const std::vector<int> vec) {
    for (std::vector<int>::const_iterator cit = vec.begin(); cit != vec.end(); ++cit)
        std::cout << *cit << " ";
    std::cout << "\n";
 }

 int main(){
    std::vector<int> v1(7,0);
    std::vector<int> v2 = {1,2,3,4,5,6,7};
    std::vector<int> v3 = {1,2,3,4,5,6,7};
    std::vector<int> v4 = {1,2,3,4,5,6,7};
    std::vector<int> v5 = {1,2,3,4,5,6,7};
    std::vector<int> v6 = {1,2,3,4,5,6,7};
    std::vector<int> v7 = {1,2,3,4,5,6,7};

    std::vector<std::vector<int>> vec2d {v1,v2,v3,v4,v5,v6,v7};

    std::for_each(vec2d.cbegin(), vec2d.cend(), print_vector);
 }