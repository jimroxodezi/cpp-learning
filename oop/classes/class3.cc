#include <iostream>

class Point3D {
    private:
    double _x;
    double _y;;
    double _z;

    public:
    // default unparameterized constructor
    // Point3D(): _x{0}, _y{0}, _z{0} {
    //     std::cout << "Default unparameterised constructor\n";
    //     _x = 0;
    //     _y = 0;
    //     _z = 0;
    // }

    // new faster method of initialisation
    Point3D(): _x{0}, _y{0}, _z{0} {}

    // default parameterised constructor
    // Point3D(double p_x, double p_y, double p_z){
    //     std::cout << "Default parameterised constructor\n";
    //     _x = p_x;
    //     _y = p_y;
    //     _z = p_z;
    // }

    // new method for parameterized construction
    Point3D(double p_x, double p_y, double p_z): _x{p_x}, _y{p_y}, _z{p_z} {}

    // copy constructor
    // Point3D(const Point3D &p) {
    //     std::cout << "Copy constructor\n";
    //     _x = p._x;
    //     _y = p._y;
    //     _z = p._z;
    // }

    // new method for copy constructor
    Point3D(const Point3D &p): _x{p._x}, _y{p._y}, _z{p._z} {}

    // destructor
    ~Point3D(){}

    // better done with operator overloading
    // void print(){
    //     std::cout << "x: " << _x << " y: " << _y << " z: " << _z;
    //     std::cout << std::endl;
    // }

    // setters and getters
    void set_x(double x) {
        if (x >= 0) {
            _x = x;
        }
    }

    void set_y(double y) {
        if (y >= 0) {
            _y = y;
        }
    }

    void set_z(double z) {
        if (z >= 0) {
            _z = z;
        }
    }

    void set(double x, double y, double z) {
        set_x(x);
        set_y(y);
        set_z(z);
    }

    // getters
    double x() const {
        return _x;
    }

    double y() const {
        return _y;
    }

    double z() const {
        return _z;
    }

    // operator overloading
    Point3D operator+ (const Point3D &p) {
        Point3D tmp;
        tmp.set_x(x() + p.x());
        tmp.set_y(y() + p.y());
        tmp.set_z(z() + p.z());

        return tmp;
    }

    Point3D operator- (const Point3D &p) {
        Point3D tmp;
        tmp.set_x(x() - p.x());
        tmp.set_y(y() - p.y());
        tmp.set_z(z() - p.z());

        return tmp;
    }

    // inefficient. Re-write!
    Point3D& operator* (const Point3D &p) {
        Point3D tmp;
        tmp.set_x(x() * p.x());
        tmp.set_y(y() * p.y());
        tmp.set_z(z() * p.z());

        return tmp;
    }

    Point3D operator/ (const Point3D &p) {
        if (p.x() == 0 || p.y() == 0 || p.z() == 0) {
            throw std::overflow_error("Cannot divide by zero");
        }
        Point3D tmp;
        tmp.set_x(x()/p.x());
        tmp.set_y(y()/p.y());
        tmp.set_z(z()/p.z());

        return tmp;
    } 

    Point3D operator=(const Point3D &p) {
        set_x(p.x());
        set_y(p.y());
        set_z(p.z());

        return *this;   // this is a pointer to the class instance.
    }

    bool operator==(const Point3D &p) {
        return (this->_x == p.x() && this->_y == p.y() \
        && this->_z == p.z());
    }
    
    bool operator!=(const Point3D &p) {
        return !(*this == p);
    }

    Point3D &operator++() {
        set_x(this->_x + 1);
        set_y(this->_y + 1);
        set_z(this->_z + 1);

        return *this;
    }

    Point3D &operator++(int p) {
        Point3D temp = *this;
        ++*this;
        return temp;
    }

    Point3D &operator--() {
        set_x(this->_x - 1);
        set_y(this->_y - 1);
        set_z(this->_z - 1);

        return *this;   // this is pointer to the class instance.
    }

    Point3D &operator--(int p) {
        Point3D temp = *this;
        --*this;
        return temp;
    }

    // std::ostream is the datatype of cout
    friend std::ostream &operator<<(std::ostream &out, const Point3D &p) {
            out << "x: " << p.x() << " y: " << p.y() << " z: " << p.z();
            return out;
    }

    friend std::istream &operator>>(std::istream &in, Point3D &p) {
        double tmp;
        in >> tmp;
        p.set_x(tmp);
        in >> tmp;
        p.set_y(tmp);
        in >> tmp;
        p.set_z(tmp);

        return in;
        
    }

};


int main() {
    Point3D q;
    Point3D r(3.2, 4.1, 5.3);
    Point3D s(r);

    // q.set(1, 1, 1);

    Point3D a = q + r;
    Point3D b = q - r;
    Point3D c = r * s;
    Point3D d = r / q;

    // a.print();
    std::cout << a << std::endl;
    // b.print();
    std::cout << b << std::endl;
    // c.print();
    std::cout << c << std::endl;
    // d.print();
    std::cout << d << std::endl;

    std::cin >> q;
    std::cout << q <<'\n';  // wow!
 
    std::cout << (s ==  r) << "\t"<< (q != r) << "\n"; // 1 1
    std::cout << (s != r) << "\t" << (q ==  r) << "\n"; // 0 0

    return 0;
}