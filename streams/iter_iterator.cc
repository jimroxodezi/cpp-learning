#include <vector>


int main(void) {

    std::vector<int> vec{1,2,3,4,5};

    auto rend = std::make_reverse_iterator(vec.begin());
    // same as above
    auto rend = vec.rend();
}