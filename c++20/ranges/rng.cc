#include <ranges>
#include <iostream>
#include <vector>
#include <numeric>



int main(void) {
    auto v = std::vector{1,3,6,8,9,7,6}; // same as std::vector<int> v = {1,3,6,8,9,7,6};
    auto rng = v | std::views::filter([](int x){return x > 5;});
    auto res = std::accumulate(rng.begin(), rng.end(), 0);
    std::cout << res << '\n';
}