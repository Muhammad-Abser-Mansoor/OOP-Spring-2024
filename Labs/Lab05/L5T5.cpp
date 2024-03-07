/* Programmer:Muhammad Abser Mansoor
 * Date: 01/03/2024
 * Descrption: Example of aggregation and composition
 */

#include <iostream>
#include <vector>

class Engine {
public:
    void start() {
        std::cout << "Engine started\n";
    }
};

class Wheel {
private:
    float diameter;

public:
    Wheel(float diameter) : diameter(diameter) {}

    float getDiameter() {
        return diameter;
    }
};

class Headlight {
public:
    void turnOn() {
        std::cout << "Headlight turned on\n";
    }
};

class Steering {
public:
    void steer() {
        std::cout << "Car is being steered\n";
    }
};

class Car {
private:
    Engine* engine;
    std::vector<Wheel> wheels;
    std::vector<Headlight> headlights;
    Steering steering;

public:
    Car(Engine* carEngine, std::vector<Wheel> carWheels,
        std::vector<Headlight> carHeadlights, Steering carSteering)
        : engine(carEngine), wheels(carWheels), headlights(carHeadlights), steering(carSteering) {}

    void start() {
        engine->start();
    }

    void drive() {
        steering.steer();
        std::cout << "Car is moving\n";
    }

    void turnOnLights() {
        for (auto headlight : headlights) {
            headlight.turnOn();
        }
    }

    void displayCarInfo() {
        std::cout << "Car Information:\n";
        std::cout << " - Wheels: ";
        for (auto wheel : wheels) {
            std::cout << wheel.getDiameter() << " inches \n";
        }
        std::cout << "\n";
    }
};

int main() {
    // Creating components
    Engine carEngine;
    std::vector<Wheel> carWheels = {Wheel(17.0), Wheel(17.0), Wheel(17.0), Wheel(17.0)};
    std::vector<Headlight> carHeadlights = {Headlight(), Headlight()};
    Steering carSteering;

    // Creating a car
    Car myCar(&carEngine, carWheels, carHeadlights, carSteering);

    // Using the car
    myCar.start();
    myCar.turnOnLights();
    myCar.drive();
    myCar.displayCarInfo();

    return 0;
}
