#include <iostream>

class Vector {
    private:
        double *_elem;  // data members of the vector
        int _size;  // size of the vector - number of elements

    public:

        // initializer_list constructor
        Vector(std::initializer_list<double> lst)
            : _elem{new double[lst.size()]}, _size{(int)lst.size()} {
                //copy the vlaue in the initializer_list into elem
                std::copy(lst.begin(), lst.end(), _elem);
            }
        // same as
        // Vector(std::initializer_list<double> lst) {
        //     _elem = new double[lst.size()];
        //     _size = (int)lst.size();

        //     std::copy(lst.begin(), lst.end(), _elem);
        // }


        // Copy constructor
        Vector(const Vector &v) : _elem{new double[v._size]}, _size{v.size()} {
                for (int i = 0; i != v._size; i++)
                {
                    _elem[i] = v._elem[i];
                }       
        }

        ~Vector() {
            delete []_elem;
        }

        int size() const {
            return _size;
        }

        // both a setter and a getter
        double &operator[](int i) {
            return _elem[i];
        }
};

int main() {

    Vector f{1, 2, 3};

    std::cout << f.size() << "\n";

    f[0] = 10;
    f[1] = 20;

    for (int i = 0; i < f.size(); i++)
    {
        std::cout << f[i] << " ";
    }
    std::cout << std::endl;
    

    return 0;
}