#include <iostream>

template <typename T>
const T& min(const T& a, const T& b){
    return a < b ? a : b;
}

template <typename T>
const T& max(const T& a, const T& b){
    return a > b ? a : b;
}

int main(){
    float x = -2.09, y = 1.02;

    std::cout << min(x,y) << "\t" << max(x,y) << "\n";
    std::cout << std::min(x,y) << "\t" << std::max(x,y) << "\n"; // stl min and max functions

    return 0;
}