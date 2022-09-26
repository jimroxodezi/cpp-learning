#include <iostream>

typedef struct _point_3D {
    double x;
    double y;
    double z;

    void (*init)(struct _point_3D *, double, double, double);
    void (*print)(struct _point_3D *);
}Point3D;

// typedef struct _point_3D Point3D;

void set_point(Point3D *p, double p_x, double p_y, double p_z) {
    p->x = p_x;
    p->y = p_y;
    p->z = p_z;
}

void print_point(Point3D *p) {
    std::cout << p->x << ", " << p->y << ", " << p->z << "\n";
}


int main() {
    Point3D p;
    // print_point(&p);
    // set_point(&p, 10, 20, 30);
    // print_point(&p);
    p.init = set_point;
    p.print = print_point;

    p.print(&p);
    p.init(&p, 10, 20, 30);
    p.print(&p);

    return 0;
}