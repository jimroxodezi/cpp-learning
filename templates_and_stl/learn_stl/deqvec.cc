#include <iostream>
#include <vector>
#include <deque>
/*
A deque and a vector are entirely different data structures.

Drawbacks of vector:
    1. Expensive reallocation
    2. Requires contiguous memory

*/

// int main() {

//     std::vector<int> vec = {2,3,4,5};   // size and capacity are intially the same
//     std::cout << "vec's size: " << vec.size() << std::endl;
//     std::cout << "vec's capacity: " << vec.capacity() << std::endl;

//     vec.push_back(6);
//     std::cout << "After push_back, size: " << vec.size() << '\n';
//     std::cout << "After push_back, capacity: " << vec.capacity() << '\n';

//     vec.push_back(7);
//     vec.push_back(8);
//     vec.push_back(9);
//     vec.push_back(0);
//     std::cout << "After push_back, size: " << vec.size() << '\n';
//     std::cout << "After push_back, capacity: " << vec.capacity() << '\n';

//     vec.shrink_to_fit();
//     std::cout << "After shrink_to_fit(), size: " << vec.size() << '\n';
//     std::cout << "After shrink_to_fit(), capacity: " << vec.capacity() << '\n';
// }

// class dog{};

// int main() {

//     std::vector<dog> vec(6);    // 6 dogs created with default constructor
//     std::cout << "vec: size=" << vec.size() << "    capacity=" << vec.capacity() <<'\n';

//     std::vector<dog> vec2; // vec2.capacity() == 0, vec2.size() == 0
//     vec2.resize(6); // create 6 dogs with default constructor
//     std::cout << "vec2: size=" << vec2.size() << "    capacity=" << vec2.capacity() <<'\n';

//     //example 3
//     std::vector<dog> vec3;
//     vec3.reserve(6); // no default constructor invoked.
//     std::cout << "vec3: size=" << vec3.size() << "    capacity=" << vec3.capacity() <<'\n';

// }


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