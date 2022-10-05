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
}