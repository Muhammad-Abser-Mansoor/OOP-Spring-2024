/* Programmer:Muhammad Abser Mansoor
 * Date: 18/03/2024
 * Descrption: Electric Car
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Vehicle {

    public:
    std::string make, model;
    int year;

    Vehicle(std::string make, std::string model, int year) : make(make) , model(model) , year(year) {}
};

class Car : public Vehicle {

    public:
    int door;
    double fuel_efficiency;

    Car(std::string make, std::string model, int year, int doors, double eff) : Vehicle(make,model,year) , door(doors) , fuel_efficiency(eff) {}
};

class ElectricCar : public Car {

    public:
    int battery_life;

    ElectricCar(std::string make, std::string model, int year, int doors, double eff, int life) : Car(make,model,year,doors,eff) , battery_life(life) {}

    void Run() {
        std::cout << "It do go down";
    }
};

int main() {

    ElectricCar Ecar("good make","new one",2005,4,60.2,6);
    Ecar.Run();
}
