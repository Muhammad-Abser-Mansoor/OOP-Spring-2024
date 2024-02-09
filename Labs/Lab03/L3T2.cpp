/*
 * Programmer: Muhammad Abser Mansoor 23K-0030
 * Date: 9/2/24
 * Desc: Boardmaker class
 */

#include <iostream>
#include <string>

using namespace std;

class BoardMaker {
    string brand;
    string shade;
    bool refillable;
    bool inkstatus;
    public:
    string getbrand() {
        return brand;
    }

    string getshade() {
        return shade;
    }

    bool getrefil() {
        return refillable;
    }

    bool getstatus() {
        return inkstatus;
    }

    void setter(string bran,string shad,bool refillabl,bool inkstatu) {
        brand = bran;
        shade = shad;
        refillable = refillabl;
        inkstatus = inkstatu;
        return;
    }

    void checkink(bool status) {
        if (status) {
            cout << "Still more ink" << endl;
        }
        else {
            cout << "No more ink " << endl;
        }
        return;
    }

    void checkrefil(bool refil) {
        if (refil) {
            cout << "Can be refilled" << endl;
        }
        else {
            cout << "Cannot be refilled " << endl;
        }
        return;
    }
};

int main() {
    string a,b;
    bool c,d;
    
    cout << "Enter brand name ";
    cin.ignore();
    getline(cin,a);

    cout << "Enter shade ";
    cin.ignore();
    getline(cin,b);

    cout << "Enter inkstatus ";
    cin >> c;

    cout << "Enter refillability ";
    cin >> d;

    BoardMaker board;
    board.setter(a,b,c,d);
    d = board.getrefil();
    a = board.getbrand();
    b = board.getshade();
    c = board.getstatus();
    board.checkink(c);
    board.checkrefil(d);
}
