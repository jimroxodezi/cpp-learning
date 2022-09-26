#include <iostream>
#include "rectangle.h"

int main() {
    rectangle r(10, 20);

    std::cout << r.area() << " " << r.perimeter() <<'\n';
    return 0;
}