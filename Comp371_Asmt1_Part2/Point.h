#ifndef POINT_H
#define POINT_H

class Point {
private:
    int x, y, z;

public:
    Point(int x = 0, int y = 0, int z = 0);
	Point(const Point& other);
    ~Point();

    int getX();
    int getY();
    int getZ();

    int translate(int d, char axis);

    void display();
};

#endif