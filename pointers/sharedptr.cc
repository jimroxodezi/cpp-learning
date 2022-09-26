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
    // 1. Gunner is created, 2. p is created
    std::shared_ptr<dog> p(new dog("Master"));
    {
        std::shared_ptr<dog> p2 = p;
        p2->bark();     // no memory leak when the scope ends
        std::cout << p.use_count() << '\n';
    }   // p2 is automatically deleted here.
    p->bark(); // memory leak when foo() goes out of scope.
} // p is automatically deleted here

int main() {
    foo();
   
   // bad way of using the shared_ptr
   dog *d = new dog("Roger");
   std::shared_ptr<dog> p(d);   // d gets deleted after p goes out of scope
   std::shared_ptr<dog> p2(d);  // d gets deleted again (trouble) after p2 goes out of scope

    // faster and safer operation
   std::shared_ptr<dog> p3 = std::make_shared<dog>("Tank");

   (*p3).bark();

    return 0;
}