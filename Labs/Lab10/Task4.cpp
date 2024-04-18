#include <iostream> 
using namespace std; 
class printClass;
class perimeter {
    int length;
    int breadth;
    
    public:
    
    perimeter(int l, int b) : length(l) , breadth(b) {}
    
    friend class printClass;
    
};
class printClass{
    public:
    void display(perimeter p1) {
        cout << 2*(p1.length + p1.breadth);
    }
};

int main() {
    perimeter p2(4,5);
    printClass s;
    s.display(p2);
}
