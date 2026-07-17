#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

class Triangle {
private:
    Point* vertex_1;
    Point* vertex_2;
    Point* vertex_3;

public:
    Triangle(Point p1, Point p2, Point p3);
    Triangle(); // default constructor: all three pointers set to null
    ~Triangle();

    int translate(int d, char axis);
    double calcArea();
    void display();
};

#endif