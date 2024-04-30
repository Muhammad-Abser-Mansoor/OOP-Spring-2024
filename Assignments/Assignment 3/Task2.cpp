/* Programmer:Muhammad Abser Mansoor
 * Date: 28/03/2024
 * Descrption: Security System
 */

#include <iostream>
#include <string>

template <typename T>
class Pet{

    public:

    std::string name;
    int age;

    Pet(std::string name, int age) : name(name) , age(age) {}

    void virtual makeSound() = 0;

    std::string getName() { return name; }
    int getAge() { return age; }
};

class Cat : public Pet<Cat> {

    public:

    Cat(std::string name, int age) : Pet<Cat>(name,age) {}

    void makeSound() {
        std::cout << "Meow\n";
    }
};

class Dog : public Pet<Dog> {

    public:

    Dog(std::string name, int age) : Pet<Dog>(name,age) {}

    void makeSound() {
        std::cout << "Woof\n";
    }
};

class Bird : public Pet<Bird> {

    public:

   Bird (std::string name, int age) : Pet<Bird>(name,age) {}

    void makeSound() {
        std::cout << "Tweet\n";
    }
};

int main() {

    Pet<Cat> *cat = new Cat("Tom", 3);
    Pet<Dog> *dog = new Dog("Spike", 6);
    Pet<Bird> *bird = new Bird("Tweety", 2);

    cat->makeSound();
    dog->makeSound();
    bird->makeSound();

    return 0;
}
