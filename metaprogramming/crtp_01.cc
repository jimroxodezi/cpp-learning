#include <cstdio>

template <class Derived>
struct Base
{
    void name() {
        static_cast<Derived*>(this)->impl();
    }
};

struct D1 : public Base<D1>
{
    void impl() {
        std::puts("D1::impl()");
    }
};

struct D2 : public Base<D2>
{
    void impl() {
        std::puts("D2::impl()");
    }
};



int main(void) {
    D1 d1;
    D2 d2;
    d1.name();
    d2.name();
}