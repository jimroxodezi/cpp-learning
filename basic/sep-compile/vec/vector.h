

class Vector {
    public:
        Vector(int s);
        Vector(std::initializer_list<double>);
        double& operator[](int i);
        int size();
        ~Vector();

    private:
        int sz; // size of the vector
        double* _elem;
};