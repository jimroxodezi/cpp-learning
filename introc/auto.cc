#include <iostream>
#include <vector>

int main(){

    std::vector<int> v = {2, 4, 6, 8, 10};

    // use auto for short-lived variables
    for (auto j = v.begin(); j != v.end(); j++) {
    // for (std::vector<int>::iterator j = v.begin(); j != v.end(); j++)
        std::cout << *j << " ";
    }
    std::cout << std::endl;

    for (auto &j : v) {
        j += 3;
    }

    // same as the first one 
    for (const auto &j : v) {
        std::cout << j << " ";
    }
    std::cout << "\n";

    return 0;
}