/* Programmer:Muhammad Abser Mansoor
 * Date: 18/03/2024
 * Descrption: Student Database
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Course {

    public:
    std::string code;
    std::string name;
    int credhours;
    Course(std::string code = "", std::string name  = "", int credhours = 0) : code(code), name(name), credhours(credhours) {}
};

class Student {

    std::string ID;
    std::string name;
    Course* courses;
    int numcourse;

    public:

    Student(std::string ID, std::string name) : ID(ID) , name(name) , courses(nullptr) , numcourse(0) {}

    void enroll(Course course) {

        Course *newcourses = new Course[++numcourse];

        for (int i = 0; i < numcourse-1; i++) {

            newcourses[i] = courses[i];
        }
        // We copy the previous array and now will delete the previous one for replacement

        delete[] courses;

        courses = newcourses;
        courses[numcourse-1] = course; // Adding the new course
    }

    void drop(Course course) {

        Course *newcourses = new Course[numcourse-1];
        for (int i = 0, j = 0; i < numcourse; i++, j++) {
            if (courses[i].code == course.code) {
                j--;
                continue;
            }
            newcourses[j] = courses[j];
        }
        delete[] courses;
        courses = newcourses;
        numcourse -= 1;
    }

    int getTotalCredHours() {

        int total;
        for (int i = 0; i < numcourse; i++) {

            total += courses[i].credhours;
        }
        return total;
    }

    void printEnrolledCourses() {

        for (int i = 0; i < numcourse; i++) {

            std::cout << "Details for Course " << i+1 << ": \n";
            std::cout << "Code: " << courses[i].code << std::endl; 
            std::cout << "Name: " << courses[i].name << std::endl;
            std::cout << "Credit Hours: " << courses[i].credhours << std::endl << std::endl; 
        }
    }
};

int main() {
    Course mvc("1", "Multi-Variable Calculus", 3);
    Course oop("2", "Object Oriented Programming", 3);
    Course ew("3", "Expository Writing", 2);

    Student student("1", "Abser");

    student.enroll(mvc);
    student.enroll(oop);
    student.enroll(ew);

    student.printEnrolledCourses();
    student.drop(mvc);
    std::cout << "Total Credit Hours: " << student.getTotalCredHours() << std::endl;

    std::cout << std::endl;
    student.printEnrolledCourses();

    return 0;
}
