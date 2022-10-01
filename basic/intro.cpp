#include <iostream>
#include <string>


int main(){


    // c-style strings that are static. Their size cannpot be changed
    char statement_a[] = {'H', 'i'}; // char array not null terminated. unpredictable output
    char statement_b[] = "Hi"; // mutable...can be edited
    // char *statement_c = "Hi"; // immutable....read-only. Not supported by ISO C++

    // printf("%s\n", statement_b);

    std::string s1("Yello");
    std::string s2;
    std::string s3 = "Hey";

    s1[0] = 'H';

    std::cout << s1 << '\t' << s3 << '\n';

    std::getline(std::cin, s2);
    std::cout << s2 << std::endl;

    char name[100];
    std::cin.getline(name, sizeof(name));
    std::cout << name << "\n";

    std::cout << s1.size() << std::endl;
    s1 = "Hello there. How are you?";
    std::cout << s1.size() << std::endl;

    return 0;
}