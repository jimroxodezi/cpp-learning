#include <iostream>
#include <vector>

/*
Enumerations are used to represent small sets of integer values. They are used 
to make code more readable and less error-prone than it would have been had the 
symbolic (and mnemonic) enumerator names not been used.
*/

enum class Color{red, yellow, green};
enum class Traffic_light{red, yellow, green};

Color col = Color::red;
Traffic_light light = Traffic_light::red;




int main() {
    Color col1 = Color::red;
    // std::cout << col1 <<'\n';

    std::cout << sizeof(std::vector<int>) << '\n';
    std::cout << sizeof(std::vector<double>) << '\n';
    std::cout << sizeof(std::vector<std::string>) << '\n';

    return 0;
}