#include <iostream>

// struct Vector {
//     int sz;
//     double *elem;
// };

// void init_vector(Vector &v, int size) {
//     v.sz = size;
//     v.elem = new double[size];
// }

// double read_and_sum(Vector &v,int s) {
//     // Vector v;
//     init_vector(v,s);

//     for (int i = 0; i != s; ++i)
//     {
//         std::cin >> v.elem[i];
//     }

//     double sum = 0;
//     for (int i = 0; i != s; ++i)
//     {
//         sum += v.elem[i];
//     }
//     return sum;
    
// }

// int main() {
//     Vector v;
//     std::cout << read_and_sum(v, 10) <<'\n';
// }

class Vector {
    public:
        Vector(int i) : elem{new double[i]}, sz{i} {}
        double& operator[](int i){ return elem[i];}
        int size() {return sz;}
    private:
        int sz;
        double *elem;

};


double read_and_sum(int s) {
    Vector v(s);
    // init_vector(v,s);

    for (int i = 0; i != s; ++i)
    {
        std::cin >> v[i];
    }

    double sum = 0;
    for (int i = 0; i != s; ++i)
    {
        sum += v[i];
    }
    return sum;
    
}

int main() {
    // std::cout << read_and_sum(10) <<'\n';
    std::cout << sizeof(Vector) << '\n';
    std::cout << sizeof(double*) << '\n';
    std::cout << sizeof(double) << '\n';
    std::cout << sizeof(int*) << '\n';
    std::cout << sizeof(int) << '\n';
    std::cout << sizeof(float) <<'\n';
    std::cout << sizeof(float*) <<'\n';
}
