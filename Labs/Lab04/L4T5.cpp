/* Programmer: Muhammad Abser Mansoor
 * Date: 15/2/2024
 * Desc.: Revised Office class
 */

 #include <iostream>
 #include <string>
 #include <vector>

class Office{

    std::string Location;
    int SeatingCapacity;
    std::string *furniture;

    public:

    Office() : Location("") , SeatingCapacity(0) , furniture(nullptr) {} // Default Constructor

    Office(std::string fur1, std::string fur2, std::string fur3, std::string loc, int cap, int size) : Location(loc) , SeatingCapacity(cap) {
    
        furniture = new std::string[size]; // DMA
        furniture[0] = fur1;
        furniture[1] = fur2;
        furniture[2] = fur3;
    }
    
    ~Office() { // Destructor
        delete[] furniture;
    }
};

int main() {
    
    Office *office1 = new Office("Table","Kursi","Feder","Russia",500,3);
    delete office1;
}
