#include <iostream>


struct Thing {
    int size;
    std::string name;
};

std::ostream& operator <<(std::ostream& sm, const Thing& t) {
    sm << "Name of thing is " << t.name << " of size " << t.size << std::endl;
    return sm;
}

std::istream& operator >>(std::istream& sm, Thing& t) {
    sm >> t.name;
    sm >> t.size;
    return sm;
}


int main(void) {
    Thing t{23, "Shoe"};
    std::cout << t;

    std::cin >> t;
    std::cout << t;
}