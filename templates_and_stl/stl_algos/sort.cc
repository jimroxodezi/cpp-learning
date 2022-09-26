#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> vec = {8,9,9,10};
    std::vector<int> vec2 = {7,9,10};
    std::vector<int> vec_out;

    std::merge(vec.begin(), vec.end(), 
                vec2.begin(), vec2.end(), 
                vec_out.begin());
}