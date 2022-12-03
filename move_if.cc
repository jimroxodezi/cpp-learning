#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>


// simulating move_if using std::make_move_iterator adaptor
int main(void) {
    auto vec = std::vector{1,2,3,4,5,6,7,8};
    auto vec2 = std::vector(8,0);

    auto is_odd = [](auto i) {return i%2==1;};

    std::copy_if(std::make_move_iterator(vec.begin()), 
                std::make_move_iterator(vec.begin()+7),
                vec2.begin(), is_odd);

    std::ostream_iterator<int> cout_it(std::cout, ", ");
    std::copy(vec2.begin(), vec2.end(),cout_it);
}