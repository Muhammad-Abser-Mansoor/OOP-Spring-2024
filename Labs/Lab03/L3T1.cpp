/*
 * Programmer: Muhammad Abser Mansoor 23K-0030
 * Date: 4/2/24
 * Desc: Waterbottle class
 */

#include <iostream>
#include <string>

using namespace std;

class WaterBottle {
    string company;
    string color;
    int cap;
    public:
    
    void setter(string com, string col,int c) {
        company = com;
        color = col;
        cap = c;
    }

    string getcompany() {
        return company;
    }

    string getcolor() {
        return color;
    }

    int getcap() {
        return cap;
    }

    void answer(double ans) {
        if (ans >= 1000) {
            cout << ans << "litres";
        }
        else {
            cout << ans << " millilitres";
        }
    }
};

int main() {
    string a,b;
    int c,con;
    WaterBottle bot1;

    cout << "Enter the company name of the bottle ";
    cin.ignore();
    getline(cin,a);

    cout << "Enter the color of bottle ";
    cin.ignore();
    getline(cin,b);

    cout << "Enter capacity "; 
    cin >> c;

    bot1.setter(a,b,c);

    // For output

    cout << "Enter water consumed ";
    cin >> con;
    c = bot1.getcap();
    double ans = c - con;

    bot1.answer(ans);
}
