#include <iostream>
#include <vector>
#include <algorithm>

// using namespace std;


int main() {
    std::vector<int> vec;
    vec.push_back(2);
    vec.push_back(6);
    vec.push_back(1);
    vec.push_back(8);

    std::vector<int>::iterator  itr = vec.begin();
    auto itr2 = vec.end();

    for (; itr != itr2; ++itr) std::cout << *itr << " ";
    std::cout<<std::endl;

    // std::sort(itr, itr2);

    std::cout << *(vec.end()-1) << '\n';
    std::cout << *vec.begin() <<'\n';
    std::cout << vec.capacity() << '\n';
}