#include <iostream>
#include <memory>
#include <string>


class dog {
    std::string _name;

    public:
        dog(std::string name): _name{name} {
            std::cout << "Dog created: " << _name << '\n';
        }
        dog() { std::cout << "Nameless dog created!\n"; }
        ~dog() { std::cout << "dog " << _name << " destroyed\n"; }
        void bark() { std::cout << "Dog " << _name << " rules!\n"; }
};

void foo() {

    std::shared_ptr<dog> p = std::make_shared<dog>("Gunner");
    std::shared_ptr<dog> p1 = std::make_shared<dog>("Tank"); // this will be on top of foo() stack
    //     p = p1; // Gunner is deleted
    //     p = nullptr; // Gunner is deleted
    //     p.reset(); //Gunner is deleted

    // use of a custom deleter
    std::shared_ptr<dog> p3 = std::shared_ptr<dog>(new dog("Roger"), 
                                [](dog *p){std::cout << "custom deleter\n"; delete p;});
}

int main() {
    foo();

    return 0;
}