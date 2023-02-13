#include <iostream>

#include "arr.hpp"



int main(void) {

    array<uint64_t, 10> a = {1,2,3,4,5};

    std::cout << a.size() << " elements\n";

    for (array<uint64_t, 10>::iterator it = a.begin();
            it != a.end(); ++it) {
                std::cout << *it << " ";
            }
    std::cout<<std::endl;
}