#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>


class Container {
    public:
        virtual double& operator[](int) = 0;
        virtual int size() const = 0;
        virtual ~Container(){}
};


void use(Container& c) {
    const int sz = c.size();

    for (int i = 0; i != sz; ++i) 
        std::cout << c[i] << " ";

    std::cout << '\n';
}

// Vector_container implements Container interface
class Vector_container: public Container {
    std::vector<double> v;
    public:
        Vector_container(int s): v(s) {}
        Vector_container(std::initializer_list<double> iv): v(iv) {}
        ~Vector_container() {}

        double& operator[](int i) { return v[i];}
        int size() const {
            return v.size();
        }
};

// List_container implements Container interface
class List_container: public Container {
    std::list<double> ld;

    public:
        List_container() {}
        List_container(std::initializer_list<double> il): ld(il) {}
        ~List_container() {}

        double& operator[](int i);
        int size() const {
            return ld.size();
        }
};

double& List_container::operator[](int i) {
    for (auto &x : ld) {
        if (i==0) return x;
        --i;
    }
    throw std::out_of_range("List container");
}

void h() {
    List_container lc = {1,2,3,4,5,6,7,8,9};
    use(lc);
}

void g() {
    Vector_container vc = {1,2,3,4,5,6,};
    use(vc);
}


int main() {
    h();
    g();

    return 0;
}