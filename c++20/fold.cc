#include <iostream>


// use of c++ fold expressions
template <typename... V>
auto sum(V&&... values) {
    return (values + ...);
}  


int main(void) {
    std::cout << sum(1,2,3,4) << std::endl;
}