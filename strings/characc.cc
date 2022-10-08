#include <iostream>
#include <string>

int main(void) {
    /*
    * std::string is mutable.
    */

   std::string s1 = "Goodbye";
   std::cout << s1[1] << "\n";

   s1[2] = 'X';
   std::cout << s1 << "\n";
   std::cout << s1.at(2) << "\n";
//    std::cout << s1.at(20) << "\n";  // throws exception out_of_range
//    std::cout << s1[20] << "\n";

    std::cout << s1.front() << "\n";
    std::cout << s1.back() << "\n";
    s1.push_back('Z');
    std::cout << s1 << "\n";
    s1.pop_back();
    std::cout << s1 << "\n";

    std::string s3(s1.begin(), s1.begin()+3);   // use of iterators
    std::cout << s3 << "\n";

    std::cout << s3.c_str() << "\n";    
}