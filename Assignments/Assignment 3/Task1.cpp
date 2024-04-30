/* Programmer:Muhammad Abser Mansoor
 * Date: 28/03/2024
 * Descrption: Security System
 */

#include <iostream>
#include <string>

class Medicine{

    std::string name,formula;
    double price;
    int manufactureyear,expirationyear;

    public:

    Medicine() : name(""), formula(""), price(NULL), manufactureyear(NULL), expirationyear(NULL) {}

    Medicine(std::string name, std::string formula, double price, int manufacture, int expiry) : name(name) , formula(formula), price(price), manufactureyear(manufacture) , expirationyear(expiry) {}

    std::string getname() {return name;}
    std::string getformula() {return formula;}
    double getprice() {return price;}
    int getmanufacture() {return manufactureyear;}
    int getexpiration() {return expirationyear;}

    void setname(std::string name) { this->name = name; }
    void setformula(std::string formula) { this->formula = formula; }
    void setprice( double price) { this->price = price; }
    void setmanufacture(int manufacture) { this->manufactureyear = manufacture; }
    void setexpiration(int expiration) { this->expirationyear = expiration; }

    void virtual details() {
        std::cout << "Name: " << name << "\nFormula: " << formula << "\nPrice:" << price
        << "\nManufacture Date: " << manufactureyear << "\nExpiration Date: " << expirationyear;
    }

    bool operator==(const Medicine& m) const {
        return (expirationyear == m.expirationyear);
    }
};

class Tablet : public Medicine {

    int sucroselvl;

    public:

    Tablet() : Medicine() , sucroselvl(NULL) {}
    Tablet(std::string name, std::string formula, double price, int manufacture, int expiry , int sucrose) : Medicine(name,formula,price,manufacture,expiry) {

        while (sucrose != 0 && sucrose != 1) {
            std::cout << "Incorrect Input. Enter Again ";
            std::cin >> sucrose;
        }
        sucroselvl = sucrose;
    }

    void details() {
        std::cout << "Name: " << getname() << "\nFormula: " << getformula() << "\nPrice:" << getprice()
        << "\nManufacture Date: " << getmanufacture() << "\nExpiration Date: " << getexpiration() << "Sucrose Level: " << sucroselvl;
    }
};

class Capsule : public Medicine {

    int abspercentage;

    public:

    Capsule() : Medicine() , abspercentage(NULL) {}

    Capsule(std::string name, std::string formula, double price, int manufacture, int expiry , int percent) : Medicine(name,formula,price,manufacture,expiry) {

        while (percent > 100 || percent < 1) {
            std::cout << "Incorrect Input. Enter Again ";
            std::cin >> percent;
        }
        abspercentage = percent;
    }

    void details() {
        std::cout << "Name: " << getname() << "\nFormula: " << getformula() << "\nPrice:" << getprice()
        << "\nManufacture Date: " << getmanufacture() << "\nExpiration Date: " << getexpiration() << "Sucrose Level: " << abspercentage;
    }
};

class Syrup: public Medicine {

    public:

    Syrup() : Medicine() {}

    Syrup(std::string name, std::string formula, double price, int manufacture, int expiry , int percent) : Medicine(name,formula,price,manufacture,expiry) {}

    void details() {
        std::cout << "Syrup Name: " << getname() << "\nSyrup Formula: " << getformula() << "\nSyrup Price:" << getprice()
        << "\nSyrup Manufacture Date: " << getmanufacture() << "\nSyrup Expiration Date: " << getexpiration();
    }
};

class Pharmacist {
    
    public:

    void Search_Medicine(std::string formula, Medicine *prescription, int size) {

        for (int i = 0; i < size;i++) {
            if (formula == prescription[i].getformula()) {
                prescription[i].details();
                return;
            }
        }
    }
};

class Counter {

    public:

    void Search_Medicine(std::string name, Medicine *prescription, int size) {

        for (int i = 0; i < size;i++) {
            if (name == prescription[i].getname()) {
                prescription[i].details();
                return;
            }
        }
    }

    int Update_Revenue(Medicine *prescription, int size) {

        double sum;
        for (int i = 0; i < size; i++) {
            sum += prescription[i].getprice();
        }
        return sum;
    }
};
