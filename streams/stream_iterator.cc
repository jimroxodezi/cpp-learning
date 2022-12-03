#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>


// template <typename T>
// void print_vec(std::vector<T> &vec) {
//     for (auto &i: vec) {
//         std::cout << i << " ";
//     }
//     std::cout << '\n';
// }

int main(void){

    std::vector<int> vec;
    std::istream_iterator<int> cin_it(std::cin);    // input iterator
    std::istream_iterator<int> end_it{};    // end of input iterator.

    for (; cin_it != end_it; cin_it++) {
        vec.push_back(*cin_it);
    }

    // print_vec(vec);

    std::ostream_iterator<int> cout_it(std::cout, " , ");
    // for (auto& i: vec) {
    //     cout_it = i;
    // }

    std::copy(vec.begin(), vec.end()-1, cout_it);
    std::cout << vec.back() << std::endl;
}