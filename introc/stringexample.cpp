#include <iostream>
#include <string>

int main(){
    std::string s;

    if (s.empty())
    {
        std::cout << "string is empty\n"; 
    }else{
        std::cout << "string is not empty\n";
    }

    s.reserve(5);
    s = "What?";

    std::cout << "Size of s is: " << s.size() << std::endl;

    s.clear();
    if (s.empty())
    {
        std::cout << "string is empty\n"; 
    }else{
        std::cout << "string is not empty\n";
    }
    
}