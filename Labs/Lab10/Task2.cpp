#include <iostream> 
using namespace std; 

class Base{
    public:
    int a;
    Base (int x = 4) {
        a = x;
    }
    
    Base operator-- (int) {
        this->a /= 4;
        return *this;
    }
    
    Base operator-- () {
        this->a *= 4;
        return *this;
    }
    
    void display() {
        cout << "The Value is; " << a;
    }
};

int main() {
    Base b1;
    b1--;
    b1.display();
    --b1;
    b1.display();
}
