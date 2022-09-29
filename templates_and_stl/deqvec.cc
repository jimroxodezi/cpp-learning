#include <iostream>
#include <vector>
#include <deque>

/*
A deque and a vector are entirely different data structures.

Drawbacks of vector:
    1. Expensive reallocation
    2. Requires contiguous memory

deque doesn't require a contiguous chunk of memory

*/


int main() {

    std::vector<int> vec = {2,3,4,5};
    int* p = &vec[3];
    vec.push_back(6); // capacity exceeded, reallocation required
    // pointer becomes invalidated after reallocation
    std::cout << *p << std::endl;   // undefined behaviour -> gabbage value 

    std::deque<int> deq = {2,3,4,5};
    p = &deq[3];
    deq.push_back(6);
    // pointer is not invalidated!
    std::cout << *p << std::endl;
}