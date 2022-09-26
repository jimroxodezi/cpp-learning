/*
Learning proper class design from the C++PL book.
class definition contains only operation requiring access
to the representation. Many useful operation that doesn't
require access to the representation of complex can be defined
outside of the class.
*/


class complex {
    double re, im;

    public:
        complex(double r) : re{r}, im{0} {}
        complex(double r, double i) : re{r}, im{i} {}
        complex(): re{0}, im{0} {}

        double real() const {
            return re;
        }

        void real(double r) {
            re = r;
        }

        double imag() const {
            return im;
        }

        void imag(double i) {
            im = i;
        }

        complex& operator+=(complex z) {
            re += z.re;
            im += z.im;
            return *this;
        }

        complex& operator-=(complex z) {
            re -= z.re;
            im -= z.im;
        }

        complex& operator*=(complex z);
        complex& operator/=(complex z);

};

// other useful operations defined outside the class definition
// an argument passed by value is copied, hence the argument can
// be modified without affecting the caller's copy

// Note: the compiler converts operators into appropriate function 
// calls
complex operator+(complex a, complex b) {
    return a+=b;
}

complex operator-(complex a, complex b) {
    return a-=b;
}

complex operator-(complex a) {
    return {-a.real(), -a.imag()};
}

complex operator*(complex a, complex b) {
    return a*=b;
}

complex operator/(complex a, complex b) {
    return a/=b;
}

bool operator==(complex a, complex b) {
    return a.real()==b.real() && a.imag()==b.imag();
}

bool operator!=(complex a, complex b) {
    return !(a==b);
}


