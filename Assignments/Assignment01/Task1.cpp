/* Programmer: Muhammad Abser Mansoor
 * Date: 15/2/2024
 * Desc.: Pet shop database
 */

 #include <iostream>
 #include <string>
 #include <vector>

 class Pet{

    std::string hstatus;
    int hunger;
    std::string specie;
    int happy;     // Attributes
    std::vector<std::string> ss;

    public:

    Pet(std::string species) { // Default Constructor
        hstatus = "Healthy";
        hunger = 0;
        happy = 10;
        specie = species;
        char y;
        while (finish != 'y') {
            std::string skill = "";
            std::cout << "Enter special skills. If no skills are present just press enter " >> std::endl;
            cin.ignore();
            getline(cin,skill);
            ss.push_back(skill);
            std::cout << "Is that all? press y to finish ";
            std::cin >> y;
        }
    }

     Pet(std::string nhstatus, int nhunger, int nhappy, std::string species) { // Constructor
        hstatus = nhstatus;
        specie = species;
        hunger = nhunger;
        happy = nhappy;
        char y;
        while (finish != 'y') {
            std::string skill = "";
            std::cout << "Enter special skills. If no skills are present just press enter " >> std::endl;
            cin.ignore();
            getline(cin,skill);
            std::cout << "Is that all? press y to finish ";
            std::cin >> y;
        }
    }

    void displayPetDetails() {

        std::cout << "Specie: " << specie << std:;endl
        << "Health Status: " << hstatus
        << std::endl << "Hunger level: " << hunger << std::endl
        << "Happiness Level: " << happy << std::endl
        << "Special skills: " << std::endl;

        for (std::string skilz: this->ss) {
            std::cout << skilz << std::endl;
        }

    }

    void updateHappiness(int newhappy) {
        happy = newhappy;
    }

    void updateHealth(std::string newstatus) {
        hstatus = newstatus;
    }

    void updateHunger(int newhunger) {

        if (happy < 10) {
            happy -= newhunger-hungry;
            hungry = newhunger;
            return;
        }
        hungry = newhunger;
    }
 };

 class Adopter {

    std::string name;
    std::string mobilenum;
    std::vector<Pet> adoptedpetrecords;

    public:

    Adopter(std::string nname,std::string mmobilenum) {
        name = nname;
        mobilenum = mmobilenum;
    }

    void list(int numofpets) {

        char end;

        while(end != 'y') {

            std::string status,specie;
            int hunger,happy;

            std::cout << "Enter status of the adopted pet: ";
            std::cin.ignore();
            getline(std::cin,status);

            std::cout << "Enter specie of the adopted pet: ";
            std::cin.ignore();
            getline(std::cin,specie);

            std::cout << "Enter Hunger level of the adopted pet: ";
            std::cin >> hunger;

            std::cout << "Enter Happiness level of the adopted pet: ";
            std::cin >> happy;
            adoptedpetrecords.push_back(Pet(status,hunger,happy,specie));

            std::cout << "Is that all? press y to finish ";
            std::cin >> end;
        }
        return;

    }

    void adoptpet() {

        std::string status;
        std::string specie;
        int hunger,happy;

        std::cout << "Enter status of the adopted pet: ";
        std::cin.ignore();
        getline(std::cin,status);

        std::cout << "Enter specie of the adopted pet: ";
        std::cin.ignore();
        getline(std::cin,specie);

        std::cout << "Enter status of the adopted pet: ";
        std::cin.ignore();
        getline(std::cin,status);

        std::cout << "Enter Hunger level of the adopted pet: ";
        std::cin >> hunger;

        std::cout << "Enter Happiness level of the adopted pet: ";
        std::cin >> happy;
        adoptedpetrecords.push_back(Pet(status,hunger,happy,specie));

    }

    void returnpet() {

        adoptedpetrecords.erase(adoptedpetrecords.begin());
        
    }

    void displayAdoptedpets() {

        for (Pet pets: this->adoptedpetrecords) {
            std::cout << pets.displayPetDetails << std::endl;
        }

    }

 };

 int main() {

    Pet pets[2];

    for (int i = 0; i < 2; i++) {
        std::string specie;
        std::cout << "Enter specie of the pet in stock: ";
        std::cin.ignore();
        getline(std::cin,specie);
        pets[i] = Pet(specie);
    }

    pets[0].updateHappiness();
    pets[0].updateHealth();
    pets[0].updateHunger();

 }
