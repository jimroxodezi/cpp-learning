

class rectangle {
    protected:
        int _height;
        int _width;

    public:
        rectangle();
        rectangle(int h, int w);
        rectangle(const rectangle &r);
        ~rectangle();

        int height() const;
        int width() const;
        int area() const;
        int perimeter() const;
};