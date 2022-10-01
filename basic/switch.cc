#include <iostream>

bool accept();

int main() {
    accept();

    return 0;    
}

bool accept() {
    int tries = 1;
    while (tries < 4)
    {
        std::cout << "Do you want to proceed? (y or n)\n";
        char ans;
        std::cin >> ans;

        switch (ans)
        {
        case 'y':
            return true;

        case 'n':
            return false;

        default:
            std::cout << "I don't know what that means\n";
            tries++;
        }
    }

    std::cout << "I'll take that for a no\n";
    return false;
}