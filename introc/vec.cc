#include <iostream>
#include <vector>

int main(){

    std::vector<int> v = {2, 4, 6, 8, 10};

    for (auto j = v.begin(); j != v.end(); j++) {
        std::cout << *j << " ";
    }

    std::cout << std::endl;

    std::cout << "size of v is: " << v.size() << std::endl;

    std::vector<double> vect;
    if (vect.empty())
    {
        std::cout << "Vector is empty\n";
    }

    vect.push_back(3.14);
    vect.push_back(2.00);
    vect.push_back(3.100);

    for (const auto &j : vect) {
        std::cout << j << " ";
    }
    std::cout << "\n";

    vect.pop_back();
    for (const auto &j : vect) {
        std::cout << j << " ";
    }
    std::cout << "\n";

    std::vector<float> v3(9, 10.2);
    
    for (const auto &j : v3) {
        std::cout << j << " ";
    }
    std::cout << "\n";

    v3[4] = 22.2;
    v3.push_back(10.11);
    // v3.pop_back();

    for (const auto &j : v3) {
        std::cout << j << " ";
    }
    std::cout << "\n";


    
    return 0;
}