#include <iostream>
#include <algorithm>
#include <string>


int main(void) {
    std::string s1 = "Bob and Alice are like Romeo and Juliet, really";
    int count = std::count(s1.begin(), s1.end(), 'e');

    std::cout << count << '\n';

    count = std::count_if(s1.begin(), s1.end(), 
        [](char c){return c <= 'e' && c >= 'a';});

    std::cout << count << '\n';
    return 0;
}