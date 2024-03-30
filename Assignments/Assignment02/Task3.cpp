/* Programmer:Muhammad Abser Mansoor
 * Date: 18/03/2024
 * Descrption: Daraz Loyalty Program
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class DarazPersonData{

    std::string lastname,firstname,address,city,state,zip,phone;

    public:

    DarazPersonData(std::string first, std::string last, std::string addr, std::string cty, std::string st, std::string zp, std::string ph)
        : firstname(first), lastname(last), address(addr), city(cty), state(st), zip(zp), phone(ph) {}

    std::string getlastname() {return lastname;}
    std::string getfirstname() {return firstname;}
    std::string getaddress() {return address;}
    std::string getcity() {return city;}
    std::string getstate() {return state;}
    std::string getzip() {return zip;}
    std::string getphone() {return phone;}
    
    void setlastname(std::string lastname) {lastname = lastname;}
    void setfirstname(std::string firstname) {firstname = firstname;}
    void setaddress(std::string address) {address = address;}
    void setcity(std::string city) {city = city;}
    void setstate(std::string state) {state = state;}
    void setzip(std::string zip) {zip = zip;}
    void setphone(std::string phone) {phone = phone;}

};

class DarazCustomerData : public DarazPersonData{

    int customerNumber;
    int loyaltyPoints;
    static int totalCustomers;

    public:

    DarazCustomerData(std::string first, std::string last, std::string addr, std::string cty, std::string st, std::string zp, std::string ph) 
        : DarazPersonData(first, last, addr, cty, st, zp, ph), customerNumber(totalCustomers++), loyaltyPoints(0) {}

    int getCustomerNumber() { return customerNumber; }
    int getLoyaltyPoints() { return loyaltyPoints; }
    
    void setCustomerNumber(int num) { customerNumber = num; }
    void setLoyaltyPoints(int points) { loyaltyPoints = points; }
};

class DarazLoyaltyProgram{

    DarazCustomerData *customer;

    public:

    DarazLoyaltyProgram(DarazCustomerData *customer) : customer(customer) {}

    void addpoints(int points) {

        customer->setLoyaltyPoints(customer->getLoyaltyPoints() + points);
    }

    float redeempoints(int points) {

        int loyaltypoints = customer->getLoyaltyPoints();
        if (loyaltypoints - points < 0 || points < 0) { return -1.0f; }

        return 0.5f;
    }

    void displaypoints() {

        std::cout << "Total Loyalty Points: " << customer->getLoyaltyPoints() << std::endl;
    }
};

void display(DarazCustomerData &customer) {
    std::cout << "Customer ID: " << customer.getCustomerNumber() << "\n";
    std::cout << "Name: " << customer.getfirstname() + " " + customer.getlastname() << "\n";
    std::cout << "Address: " << customer.getaddress() << "\n";
    std::cout << "City: " << customer.getcity() << "\n";
    std::cout << "Phone: " << customer.getphone() << "\n";
    std::cout << "Zip: " << customer.getzip() << "\n";
    std::cout << "State: " << customer.getstate() << "\n";
}

int DarazCustomerData::totalCustomers = 0;

int main() {

    int points;
    float price;

    DarazCustomerData customer("Abser", "Mansoor", "C 141 Federal B Area", "Karachi", "Pakistan", "555", "0445213252");

    display(customer);

    DarazLoyaltyProgram program(&customer);
    program.addpoints(20);
    program.displaypoints();

    std::cout << "Enter price of item: ";
    std::cin >> price;

    std::cout << "Enter amount of loyalty points to be redeemed: ";
    std::cin >> points;

    std::cout << "Price before discount: " << price << std::endl;

    float discount = program.redeempoints(points);

    if (discount == -1) {return 1;}
    std::cout << "Price after discppunt: " << price - price * discount << std::endl;

    return 0;
}
