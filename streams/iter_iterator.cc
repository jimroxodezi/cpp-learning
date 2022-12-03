#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iterator>



template <typename T>
void print_vec(std::vector<T> &vec) {
    for (auto &i: vec) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

int main(void) {

    std::vector<int> vec{1,2,3,4,5};
    auto rend = std::make_reverse_iterator(vec.begin());
    // same as above
    // auto rend = vec.rend();

    std::ostream_iterator<std::string> cout_it(std::cout, ", ");

    std::vector<std::string> str{"make_", "move_", "iterator()"};
    auto concat = std::accumulate(str.begin(), str.end(), std::string{});

    std::cout << concat << std::endl;
    print_vec(str);

    // move semantics
    auto m_concat = std::accumulate(std::make_move_iterator(str.begin()),
                                    std::make_move_iterator(str.end()),
                                    std::string{});
    std::cout << m_concat << std::endl;
    // print_vec(str); // str moved. Now empty.
    // same as above
    std::copy(str.begin(), str.end(), cout_it); // str moved. Now empty.
}