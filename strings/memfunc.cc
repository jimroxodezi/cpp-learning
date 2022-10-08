#include <iostream>
#include <string>


int main() {
    std::string s1 = "abcdefg";
    char buf[20];

    size_t len = s1.copy(buf, 3);
    // std::cout << len << "\n";

    std::cout << buf << "\n";

    s1.copy(buf, 4, 2);
    std::cout << buf << "\n";

    s1 = "If a job is worth doing, it's worth doing well";
    size_t found = s1.find("doing");
    std::cout << found << "\n";
    std::cout << s1.find("doing", 20) << "\n";

    // std::cout << s1.find_last_of("doing") << "\n";
    return 0;
}