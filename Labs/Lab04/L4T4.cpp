/* Programmer: Muhammad Abser Mansoor
 * Date: 15/2/2024
 * Desc.: Office class
 */

 #include <iostream>
 #include <string>
 #include <vector>

class Office{

    std::string Location;
    int SeatingCapacity;
    std::string furniture[3];

    public:

    Office() : Location("") , SeatingCapacity(0) , furniture({"","",""}) {}

    Office(std::string loc) : Location(loc) {}

    Office(int cap) : SeatingCapacity(cap) {}

    Office(std::string loc, int cap) : Location(loc) , SeatingCapacity(cap) {}

    Office(std::string fur1, std::string fur2, std::string fur3, std::string loc, int cap) : furniture({fur1,fur2,fur3}) , Location(loc) , SeatingCapacity(cap) {}
};

int main() {
    
    Office office1;
    Office office2("Karachi");
    Office office3(50);
    Office office4("Lahore",100);
    Office office5("Table","Kursi","Feder","Russia",500);
}
