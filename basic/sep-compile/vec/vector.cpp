#include "vector.h"
#include <stdexcept>
#include <iostream>


Vector::Vector(int s): _elem{new double[s]}, sz{s}
{
    for (int i = 0; i != s; ++i)
    {
        _elem[i] = 0;
    }
    
}

Vector::Vector(std::initializer_list<double> lst): _elem{new double[lst.size()]},
            sz{lst.size()} {
                std::copy(lst.begin(), lst.end(), _elem);   // copy from lst to _elem
            }     

Vector::~Vector() {
    delete []_elem;
}

double &Vector::operator[](int i) {
    if (i < 0 || size() <= i) {
        throw std::out_of_range{"Index out of bounds"};
    }
    return _elem[i];
}

int Vector::size() {
    return sz;
}