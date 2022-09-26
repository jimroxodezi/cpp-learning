#include <iostream>

class scope_reporter {
    public:
    scope_reporter(){
        std::cout << "Constructor\n";
    }
    ~scope_reporter(){
        std::cout << "Destructor\n";
    }
};

void foo(){
    scope_reporter sr1;
    {
        scope_reporter sr2;
    }
    scope_reporter sr3;
}

int main(){
    foo();

    return 0;
}