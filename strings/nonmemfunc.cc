#include <iostream>
#include <string>


int main(void) {

    std::string s1 = "Goodbye!";
    std::cout << s1 << "\n";

    std::cin >> s1;

    std::getline(std::cin, s1);     // default delimiter => '\n'
    // std::getline(std::cin, s1, ';');    // delimiter => ';

    // convert number to string
    s1 = std::to_string(8);
    s1 = std::to_string(2.3e7);
    std::cout << s1 << '\n';
    s1 = std::to_string(0xABAD1DEA);
    // std::cout << s1 << '\n';

    s1 = std::to_string(034);   // convert from octal number


    // convert string to number
    s1 =  "190";
    int num = std::stoi(s1);
    std::cout << num << '\n';
}