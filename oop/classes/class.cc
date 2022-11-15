#include <iostream>

class scope_reporter {
    std::string name;
    public:
    scope_reporter(std::string _name): name{_name} {
        std::cout << "Constructing " << name << '\n';
    }
    ~scope_reporter(){
        std::cout << "Destroying " << name << '\n';
    }
};

void foo(){
    scope_reporter sr1{"sr1"};
    {
        scope_reporter sr2{"sr2"};
    }
    scope_reporter sr3{"sr3"};
}

int main(){
    foo();

    return 0;
}