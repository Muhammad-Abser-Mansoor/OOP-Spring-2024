/* Programmer:Muhammad Abser Mansoor
 * Date: 01/03/2024
 * Descrption: Square static demonstration
 */

#include <iostream>
#include <vector>

class Square {
private:
    static float allareas;  // Static variable
    float sideLength;
    float area;

public:
    // Constructors
    Square() : sideLength(0.0), area(0.0) {}

    Square(float sideLength) : sideLength(sideLength), area(0.0) {}

    void calculateArea() {

        area = sideLength * sideLength;
        allareas += area;

    }

    // Getters and Setters
    float getsideLength() const { return sideLength; }

    void setsideLength(float length) { sideLength = length; }
    
    float getarea() const { return area; }

    static float getallareas() { return allareas; }

};

// Initialisation of static var
float Square::allareas = 0.0;

int main() {
    // Creating three Square objects with different side lengths
    Square square1(2.0);
    Square square2(3.5);
    Square square3(4.0);

    // Performing required tasks
    std::cout << "Square with side length " << square1.getsideLength() << ":\n";
    square1.calculateArea();
    std::cout << "Area: " << square1.getarea() << "\n";
    std::cout << "All Areas: " << Square::getallareas() << "\n\n";

    std::cout << "Square with side length " << square2.getsideLength() << ":\n";
    square2.calculateArea();
    std::cout << "Area: " << square2.getarea() << "\n";
    std::cout << "All Areas: " << Square::getallareas() << "\n\n";

    std::cout << "Square with side length " << square3.getsideLength() << ":\n";
    square3.calculateArea();
    std::cout << "Area: " << square3.getarea() << "\n";
    std::cout << "All Areas: " << Square::getallareas() << "\n\n";

    return 0;
}
