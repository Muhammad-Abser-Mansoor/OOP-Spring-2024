#include <iostream>
#include <string>

using namespace std;

void avg (int x,int y, int z) {
    cout << "Total is " << (x + y + z)/3 << "\n\n";
    return;
}

void tot (int x,int y, int z) {
    cout << "Average is " << x + y + z << endl;
    return;
}

void gg (int x) {
    if (x >= 90) {
        cout << "A" << endl;
    }
    else if (x >= 80) {
        cout << "B" << endl;
    }
    else if (x >= 70) {
        cout << "C" << endl;
    }
    else if (x >= 60) {
        cout << "D" << endl;
    }
    else {
        cout << "F" << endl;
    }
    return;
}

int main() {
    int students;
    cout << "Enter number of students ";
    cin >> students;
    cout << "\n";
    for (int i = 0; i < students; i++) {
    int x,y,z;
    cout << "Enter English Marks ";
    cin >> x;
    gg(x);
    cout << "Enter Maths Marks ";
    cin >> y;
    gg(y);
    cout << "Enter Science Marks ";
    cin >> z;
    gg(z);
    tot(x,y,z);
    avg(x,y,z); }
    return 0;
}
