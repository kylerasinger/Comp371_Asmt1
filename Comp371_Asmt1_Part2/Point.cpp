#include "Point.h"
#include <iostream>
using namespace std;

Point::Point(int x, int y, int z) : x(x), y(y), z(z) {}

Point::Point(const Point& other) : x(other.x), y(other.y), z(other.z) {}

Point::~Point() {}

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

int Point::getZ() {
    return z;
}

int Point::translate(int d, char axis) {
    if(axis == 'x') {
        x = x + d;
    } else if(axis == 'y') {
        y = y + d;
    } else if(axis == 'z') {
        z = z + d;
    } else {
        return -1;
    }
    return 0;
}

void Point::display() {
    cout << "(" << x << ", " << y << ", " << z << ")";
}