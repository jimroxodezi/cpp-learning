#include <iostream>
#include <vector>

/* a reference is like a copy of a dereferenced pointer
    a reference is an already dereferenced pointer. 
    You can just modify it without any dereferencing
    once you have a reference to a variable, you can't have it 
    reference another variable */

// using pointers - c-style
void c_swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// using references
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void print_vector(const std::vector<float> &v) {
    for (const auto &i : v) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

void mult_by_two(std::vector<float> &v){
    for (auto &i : v) {
        i *= 2;
    }
}

int main() {
    
    int a = 10;
    int b = 20;

    std::cout << a << " " << b << "\n";

    c_swap(&a,&b);
    std::cout << a << " " << b << "\n";

    swap(a,b);
    std::cout << a << " " << b << std::endl;

    std::vector<float> f = {1.2, 2.1, 2.3, 3.3, 3.4, 4.3};

    print_vector(f);
    mult_by_two(f);
    print_vector(f);

    return 0;
}