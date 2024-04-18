#include <iostream> 
using namespace std; 

class Shape{
    public:
    int dim;
    Shape (int x = 4) {
        dim = x;
    }
    
    int Area() {
        return dim*dim;
    }
    
    int operator+ (Shape shape) {
        int sum = this->Area()+shape.Area();
        return sum;
    }
};

int main() {
    Shape shape1;
    Shape shape2;
    cout << shape1+shape2;
}
