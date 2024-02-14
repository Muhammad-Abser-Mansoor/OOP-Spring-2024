/*
 * Programmer: Muhammad Abser Mansoor 23K-0030
 * Date: 10/2/24
 * Desc: Smartphone class
 */

#include <iostream>
#include <string>

class Smartphone {
private:
    std::string brand;
    std::string model;
    std::string displayResolution;
    int ram;
    int rom;
    int storage;

public:

    // Getter methods
    std::string getBrand() const {
        return brand;
    }

    std::string getModel() const {
        return model;
    }

    std::string getDisplayResolution() const {
        return displayResolution;
    }

    int getRam() const {
        return ram;
    }

    int getRom() const {
        return rom;
    }

    int getStorage() const {
        return storage;
    }

    // Setter method
    void setter(std::string newBrand,std::string newModel,std::string newResolution,int newRam,int newRom,int newStorage) {
        brand = newBrand;
        model = newModel;
        displayResolution = newResolution;
        ram = newRam;
        rom = newRom;
        storage = newStorage;
    }

    // Rest of the functions

    void message(std::string message) {
        std::cout << "Message sent" << std::endl << message << std::endl;
    }

    void wifi_connection(std::string wifi) {
        std::cout << "connected to " << wifi << std::endl;
    }

    void browse_internet() {
        std::cout << "internet browsed" << std::endl;
    }

    void call(std::string number) {
        std::cout << number << " called" << std::endl;
    }
};

int main() {
    Smartphone phone1, phone2;

    // Object instantiations

    phone1.setter("Xiaomi","12 pro","1920x1080",4,32,32);

    phone2.setter("Samsung","galaxy s7","1920x1080",4,64,64);

    // Displaying both objects

    std::cout << phone1.getBrand() << std::endl;
    std::cout << phone1.getModel() << std::endl;
    std::cout << phone1.getRam() << std::endl;
    std::cout << phone1.getRom() << std::endl;
    std::cout << phone1.getStorage() << std::endl;
    std::cout << phone1.getDisplayResolution() << std::endl;
    phone1.wifi_connection("PhaticharCL");
    phone1.message("Let me sleep");

    std::cout << std::endl << phone2.getBrand() << std::endl;
    std::cout << phone2.getModel() << std::endl;
    std::cout << phone2.getRam() << std::endl;
    std::cout << phone2.getRom() << std::endl;
    std::cout << phone2.getStorage() << std::endl;
    std::cout << phone2.getDisplayResolution() << std::endl;
    phone2.browse_internet();
    phone2.call("amma");

    return 0;
}
