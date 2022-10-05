#include <iostream>
#include <string>

int main(void){

    std::string s1("Hello");
    std::cout << s1 << "\n";

    std::string s2("Hello", 3);
    std::cout << s2 << "\n";

    s1.resize(9, '\0');
    std::cout << s1 << "\n";
    s1.resize(12, 'X');
    std::cout << s1 << "\n";


    return 0;
}