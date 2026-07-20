#include "Triangle.h"
#include <iostream>
#include <cmath>
using namespace std;

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3)
		: vertex_1(new Point(p1)), vertex_2(new Point(p2)), vertex_3(new Point(p3)) {}

Triangle::Triangle() : vertex_1(nullptr), vertex_2(nullptr), vertex_3(nullptr) {}

Triangle::~Triangle() {
	delete vertex_1;
	delete vertex_2;
	delete vertex_3;
}
int Triangle::translate(int d, char axis) {
	if (vertex_1 == nullptr || vertex_2 == nullptr || vertex_3 == nullptr) {
        return -1;
    }
	int result1 = vertex_1->translate(d, axis);
	int result2 = vertex_2->translate(d, axis);
	int result3 = vertex_3->translate(d, axis);
	if (result1 == -1 || result2 == -1 || result3 == -1) {
		return -1;
	}
	return 0;
}

// based on heron formula https://bearboat.net/TriangleArea/Triangle.html
double Triangle::calcArea() {
	if (vertex_1 == nullptr || vertex_2 == nullptr || vertex_3 == nullptr) {
        return 0.0;
    }
	double a = sqrt(pow(vertex_2->getX() - vertex_1->getX(), 2) +
		pow(vertex_2->getY() - vertex_1->getY(), 2) +
		pow(vertex_2->getZ() - vertex_1->getZ(), 2));

	double b = sqrt(pow(vertex_3->getX() - vertex_2->getX(), 2) +
		pow(vertex_3->getY() - vertex_2->getY(), 2) +
		pow(vertex_3->getZ() - vertex_2->getZ(), 2));

	double c = sqrt(pow(vertex_1->getX() - vertex_3->getX(), 2) +
		pow(vertex_1->getY() - vertex_3->getY(), 2) +
		pow(vertex_1->getZ() - vertex_3->getZ(), 2));
	double s = (a + b + c) / 2.0;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}
void Triangle::display() {
	if (vertex_1 == nullptr || vertex_2 == nullptr || vertex_3 == nullptr) {
        cout << "Triangle has not been created yet. Please create a triangle first." << endl;
        return;
    }
	cout << "Vertex 1: ";
	vertex_1->display();
	cout << endl;
	cout << "Vertex 2: ";
	vertex_2->display();
	cout << endl;
	cout << "Vertex 3: ";
	vertex_3->display();
	cout << endl;
}