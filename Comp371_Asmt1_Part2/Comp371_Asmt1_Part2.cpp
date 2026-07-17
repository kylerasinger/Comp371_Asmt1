// 40247163, 40281850, 40284702

#include <iostream>
#include "Point.h"
#include "Triangle.h"
using namespace std;

void printMenu() {
    cout << "\n----- Triangle Menu -----\n";
    cout << "1. Create a triangle\n";
    cout << "2. Translate the triangle\n";
    cout << "3. Display the triangle coordinates\n";
    cout << "4. Calculate the triangle's area\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Triangle* myTriangle = new Triangle();
    int choice;

    do {
        printMenu();
        cin >> choice;

        switch(choice) {
            case 1: {
                int x, y, z;

                cout << "Enter x, y, z for vertex 1: ";
                cin >> x >> y >> z;
                Point p1(x, y, z);

                cout << "Enter x, y, z for vertex 2: ";
                cin >> x >> y >> z;
                Point p2(x, y, z);

                cout << "Enter x, y, z for vertex 3: ";
                cin >> x >> y >> z;
                Point p3(x, y, z);

                delete myTriangle;
                myTriangle = new Triangle(p1, p2, p3);

                cout << "Triangle successfully created.\n";
                break;   
            }
            case 2: {
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                cout << "Thank you for using the Triangle Menu. Goodbye!\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while(choice != 5);

    delete myTriangle;
    return 0;
}