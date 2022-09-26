#include "rectangle.h"

rectangle::rectangle() = default;

rectangle::rectangle(int h, int w) : _height{h}, _width{w} {}

rectangle::rectangle(const rectangle &r) : _height{r._height}, _width{r._height} {}

rectangle::~rectangle(){}

int rectangle::height() const {
    return _height;
}

int rectangle::width() const {
    return _width;
}

int rectangle::area() const {
    return _width*_height;
}

int rectangle::perimeter() const {
    return 2*(_height + _width);
}