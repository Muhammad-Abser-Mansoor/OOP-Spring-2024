#include <iostream>
#include <string>
#include <math.h>

using namespace std;

struct Register {
    int courseID;
    string coursename;
};

struct Student : Register {
    int studentID;
    string firstname;
    string lastname;
    int cellNo;
    string email;
    void display() {
        cout << "\nStudent Details are:\nStudentID: " << studentID << "\nfirstname: " << firstname << "\nlastname: " << lastname << "\ncellNo: " << "\nemail: " << email <<
        "\ncourseID: " << courseID << "coursename: " << coursename;
    }
};

int main() {
    Student arr[5];
    for (int i = 0; i < 5; i++) {
        cout << "Enter Student ID: ";
        cin >> arr[i].studentID;
        cout << "Enter Student first name: ";
        getline(cin, arr[i].firstname);

        cout << "Enter Student last name: ";
        getline(cin, arr[i].lastname);

        cout << "Enter Student Cell number: ";
        cin >> arr[i].cellNo;

        cout << "Enter Student email: ";
        getline(cin, arr[i].email);

        cout << "Enter Course ID: ";
        cin >> arr[i].courseID;

        cout << "Enter Course name: ";
        getline(cin, arr[i].coursename);

        arr[i].display;
    }
    return 0;
}
