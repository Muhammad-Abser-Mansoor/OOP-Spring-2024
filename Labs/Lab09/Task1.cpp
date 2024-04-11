#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

const double pi = 3.142;

class Shape{

    public:
    //Areas
    double circleArea(int radius) { return pi*radius*radius; }

    double rectArea(int length, int width) { return length * width; }

    double triangleArea(int base, int height) { return 0.5 * base * height; }
    //Perimeters
    double circlePerimeter(int radius) { return pi*radius*2; }

    double rectPerimeter(int length, int width) { return 2*(length+width); }

    double trianglePerimeter(int s1, int s2, int s3) { return s1 + s2 + s3; }
};

int main() {

    Shape shape;

    // Circle Calculations
    double cradius = 5.0;
    double carea = shape.circleArea(cradius);
    double cperimeter = shape.circlePerimeter(cradius);
    std::cout << "Circle Area: " << carea << std::endl;
    std::cout << "Circle Perimeter: " << cperimeter << std::endl;

    // Rectangle Calculations
    double rlength = 4.0;
    double rwidth = 6.0;
    double rarea = shape.rectArea(rlength, rwidth);
    double rperimeter = shape.rectPerimeter(rlength, rwidth);
    std::cout << "Rectangle Area: " << rarea << std::endl;
    std::cout << "Rectangle Perimeter: " << rperimeter << std::endl;

    // Triangle
    double tribase = 3.0;
    double triheight = 4.0;
    double triarea = shape.triangleArea(tribase, triheight);
    double triside1 = 5.0;
    double triside2 = 4.0;
    double triside3 = 3.0;
    double triperimeter = shape.trianglePerimeter(triside1, triside2, triside3);
    std::cout << "Triangle Area: " << triarea << std::endl;
    std::cout << "Triangle Perimeter: " << triperimeter << std::endl;

    return 0;
}
