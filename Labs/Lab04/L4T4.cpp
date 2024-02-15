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

    Office() : Location("") : SeatingCapacity(0) {}

    Office(std::string loc) : Location(loc) {}

    Office(int cap) : SeatingCapacity(cap) {}

    Office(std::string loc, int cap) : Location(loc) : SeatingCapacity(cap) {}

    Office(std::string fur1, std::string fur2, std::string fur3) :
