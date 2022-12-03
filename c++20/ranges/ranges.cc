#include <iostream>
#include <ranges>
#include <vector>

using std::views::filter;

int main(void) {
    

    std::vector<int> numbers = {6,5,4,3,2,1};
    auto is_even = [](int n) {return n%2==0; };
    auto results = numbers | filter(is_even);

    for (auto v: results) {
        std::cout << v << " ";
    }
    std::cout << '\n';
    return 0;
}