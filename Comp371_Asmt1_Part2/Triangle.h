#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

class Triangle {
private:
    Point* vertex_1;
    Point* vertex_2;
    Point* vertex_3;

public:
    Triangle(const Point &p1, const Point &p2, const Point &p3);
    Triangle(); 
    ~Triangle();

    int translate(int d, char axis);
    double calcArea();
    void display();
};

#endif