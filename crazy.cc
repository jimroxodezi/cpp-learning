#include <iostream>

auto val() {
    return -0xFFFFFFFF; // equivalent to 1.
}

int main() {
    std::cout << val() << '\n';
}

/*
EXPLANATION:
    
*/