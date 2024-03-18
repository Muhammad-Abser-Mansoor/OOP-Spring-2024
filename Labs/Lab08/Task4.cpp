/* Programmer:Muhammad Abser Mansoor
 * Date: 18/03/2024
 * Descrption: Teacher Assistant (Double Inheritance)
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Person {
    public:
    std::string name;
    int age;

    Person(std::string name, int age) : name(name) , age(age) {}
};

class Student : public Person{
    public:
    int id;
    int gradelevel;

    Student(std::string name, int age, int id, int gradelevel) : Person(name,age) , id(id) , gradelevel(gradelevel) {} 
};

class Teacher : public Person {
    public:
    std::string subject;
    int roomnumber;

    Teacher(std::string name, int age, std::string subject, int roomnumber) : Person(name,age) , subject(subject) , roomnumber(roomnumber) {}
};

class GraduateStudent : public Student, public Teacher {
    public:

    GraduateStudent(std::string name, int age, int id, int gradelevel, std::string subject, int roomnumber) : Student(name,age,id,gradelevel) , Teacher(name,age,subject,roomnumber) {}
    void Teach() {
        std::cout << "Teaching " << subject << " in room " << roomnumber << std::endl;
    }

    void Study() {
        std::cout << "Studying in Grade Level " << gradelevel << std::endl;
    }
};

int main() {

    GraduateStudent TA("Abser",18,0030,2,"OOP",6);
    TA.Teach();
    TA.Study();
}
