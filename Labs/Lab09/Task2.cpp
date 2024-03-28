#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

class Shape{

    public:

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void displayProperties() const = 0;

};

class Circle : public Shape{

    public:
    double radius;

    Circle(double radius) : radius(radius) {}

    double area() const {
        return 3.142*radius*radius;
    }

    double perimeter() const {
        return 2*3.142*radius;
    }

    void displayProperties() const {
        cout << "Properties of the Circle" << endl << "Area: " << area() << "\nPerimeter: " << perimeter() << "\nDiameter: " << 2*radius << endl;
    }

};

class Rectangle : public Shape{

    public:
    double length;
    double width;

    Rectangle(double length, double width) : length(length) , width(width) {}

    double area() const {
        return length*width;
    }

    double perimeter() const {
        return 2*(length+width);
    }

    void displayProperties() const {
        cout << "Properties of the Rectangle" << endl << "Area: " << area() << "\nPerimeter: " << perimeter() << "\nDiagonal: " << sqrt(length*length + width*width) << endl;
    }

};

class Square : public Shape{

    public:
    double side;

    Square(double side) : side(side) {}

    double area() const {
        return side*side;
    }

    double perimeter() const {
        return 4*side;
    }

    void displayProperties() const {
        cout << "Properties of the Square" << endl << "Area: " << area() << "\nPerimeter: " << perimeter() << "\nDiagonal: " << sqrt(2*side*side) << endl;
    }

};

class Triangle : public Shape{

    public:
    double side1;
    double side2;
    double side3;

    Triangle(double side1, double side2, double side3) : side1(side1) , side2(side2), side3(side3) {}

    double area() const {
        float s = (side1+side2+side3)/2;
        return sqrt(s*(s-side1)*(s-side2)*(s-side3));
    }

    double perimeter() const {
        return side1+side2+side3;
    }

    void displayProperties() const {
        cout << "Properties of the Square" << endl << "Area: " << area() << "\nPerimeter: " << perimeter() << endl;
    }

};

class EquilateralTriangle : public Triangle{

    public:

    EquilateralTriangle(double side1, double side2, double side3) : Triangle(side1,side2,side3) {}

    void isEquilateral() {
        if (side1 == side2 && side1 == side3) {
            cout << "Triangle is Equilateral\n";
        }
    }
};

int main() {

    string choice;
    int choi;
    Shape *shape;
    for (;;) {

        cout << "Please select a Shape:\n1. Circle\n2. Rectangle\n3. Square\n4. Triangle";
        cin >> choi;

        switch(choi) {

            case 1:
            shape = new Circle(15);
            break;

            case 2:
            shape = new Rectangle(10,15);
            break;

            case 3:
            shape = new Square(12);
            break;

            case 4:
            shape = new EquilateralTriangle(10,10,5);
            break;

            default:
            cout << "Incorrect choice try again\n";
            break;
        }

        cout << "Do you want to calculate properties for another shape? (yes/no): ";
        cin >> choice;
        if (choice == "yes") {
            break;
        }
    }
}
