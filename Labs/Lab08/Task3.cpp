/* Programmer:Muhammad Abser Mansoor
 * Date: 18/03/2024
 * Descrption: Library management
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Health {
    public:
    int health;
    Health(int health) : health(health) {}
};

class Position {

    public:
    int x;
    int y;
    int z;
    Position(int x, int y, int z) : x(x) , y(y) , z(z) {}
};

class Character : public Health, public Position {

    std::string name;

    public:

    Character(int health, int x, int y, int z, std::string name) : Health(health) , Position(x,y,z) , name(name) {}
    
    void display() {
        std::cout << "Health: " << health << std::endl << "x-Position: " << x << std::endl <<
        "y-Position: " << y << std::endl << "z-Position: " << z << std::endl << "Name: " << name; 
    }
};

int main() {

    Character char1(400,6,4,2,"Abser");
    char1.display();
}
