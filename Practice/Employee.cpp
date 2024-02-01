#include <iostream>
#include <string>

using namespace std;

class Employee {
    public:
    int id;
    string name;
    int salary;
    void set(string str,int d, int sal) {
        id = d;
        name = str;
        salary = sal;
    }
    void get() {
        cout << "Employee Details are :\nemployee ID: " << id << "\nEmployee name: " << name << "\nEmployee salary: " << salary << endl; 
    }
};

class Manager: public Employee {
    int depsize;
    int teamsize;
    public:
    void manset(int dsize, int tsize) {
        depsize = dsize;
        teamsize = tsize;
    }
    void gett() {
        cout << "Manager Details are :\nManager ID: " << id << "\nManager name: " << name << "\nManager salary: " << salary << "\nManager alloted department size: " << depsize << "\nManager alloted team size: " << teamsize << endl;
    }
};

int main() {
    char choice;
    cout << "Are you an employee or Manager? e for employee and any other key for manager: ";
    cin >> choice;
    if (choice == 'e') {
        int id, sal;
        string name;
        char ch;
        Employee e1;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Salary: ";
        cin >> sal;
        e1.set(name,id,sal);
        cout << "Verify data entry? y for yes: ";
        cin >> ch;
        if (ch == 'y') {
            e1.get();
        }
    }
    else {
        int id, sal,dsize,tsize;
        string name;
        char ch;
        Manager m1;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Salary: ";
        cin >> sal;
        m1.set(name,id,sal);
        cout << "Enter Department size: ";
        cin >> dsize;
        cout << "Enter Team size: ";
        cin >> tsize;
        m1.manset(dsize,tsize);
        cout << "Verify data entry? y for yes: ";
        cin >> ch;
        if (ch == 'y') {
            m1.gett();
        }
    }
    return 0;
}
