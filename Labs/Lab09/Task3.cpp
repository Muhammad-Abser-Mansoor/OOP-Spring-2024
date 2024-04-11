#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class Employee{

    std::string name;
    int ID;

    public:

    Employee(std::string name, int ID) : name(name) , ID(ID) {}

    std::string getname() {return name;}
    int getID() {return ID;}
    void setname(std::string name) {this->name = name;}
    void setID(int ID) {this->ID = ID;}
    virtual double Pay() const = 0;
    virtual void Details() const {
        std::cout << "Employee ID: " << ID << ", Name: " << name << std::endl;
    };
};

class PartTimeEmployee : public Employee{

    int hourlywage;
    int hoursworked;

    public:

    PartTimeEmployee(std::string name, int ID, int hourlywage, int hoursworked) : Employee(name, ID) , hourlywage(hourlywage) , hoursworked(hoursworked) {}

    int gethourlywage() {return hourlywage;}
    int gethoursworked() {return hoursworked;}
    void sethourlywage(int wage) {hourlywage = wage;}
    void sethoursworked(int hours) {hoursworked = hours;}
    double Pay() const { return hourlywage * hoursworked; }

    void Details() const { 
        Employee::Details();
        std::cout << "Type: Part-Time" << ",Hourly Wage: " << hourlywage << ",Hours Worked: " << hoursworked << std::endl; 
    }
};

class FullTimeEmployee : public Employee{

    int salary;

    public:

    FullTimeEmployee(std::string name, int ID, int salary) : Employee(name, ID) , salary(salary) {}

    int getsalary() {return salary;}
    void setsalary(int sal) {salary = sal;}
    double Pay() const { return salary; }

    void Details() const {  
        Employee::Details();
        std::cout << "Type: FullTime" << ",Monthly Salary: " << salary << std::endl;
    }
};

int main() {

    FullTimeEmployee fullTimeEmp("AAA", 101, 5000);
    PartTimeEmployee partTimeEmp("BBB", 102, 15, 40);

    std::cout << "Displaying Details:" << std::endl;
    fullTimeEmp.Details();
    std::cout << std::endl;
    partTimeEmp.Details();
    std::cout << std::endl;

    std::cout << "Calculating Pay:" << std::endl;
    std::cout << "Full-time Employee Pay: $" << fullTimeEmp.Pay() << std::endl;
    std::cout << "Part-time Employee Pay: $" << partTimeEmp.Pay() << std::endl;

    Employee *employee;

    employee = new FullTimeEmployee("AAA", 101, 5000);

    std::cout << "Using base class pointer to calculate Full-time Employee Pay: $" << employee->Pay() << std::endl;

    return 0;
}
