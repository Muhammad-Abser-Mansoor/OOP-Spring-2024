/* Programmer: Muhammad Abser Mansoor
 * Date: 15/2/2024
 * Desc.: Pet shop database
 */

 #include <iostream>
 #include <string>
 #include <vector>

 class Pet{
    
    public:
    std::string hstatus;
    std::string id;
    int hunger;
    std::string specie;
    int happy;     // Attributes
    std::vector<std::string> ss;

    Pet() { // Default Constructor
        hstatus = "Healthy";
        hunger = 0;
        id = "0";
        happy = 10;
        specie = "";
        char y;
        while (y != 'y') {
            std::string skill = "";
            std::cout << "Enter special skills. If no skills are present just press enter " << std::endl;
            std::cin.ignore();
            getline(std::cin,skill);
            ss.push_back(skill);
            std::cout << "Is that all? press y to finish ";
            std::cin >> y;
        }
    }

     Pet(std::string nhstatus, int nhunger, int nhappy, std::string species, std::string nid) { // Constructor
        hstatus = nhstatus;
        specie = species;
        hunger = nhunger;
        happy = nhappy;
        id = nid;
        char y;
        while (y != 'y') {
            std::string skill = "";
            std::cout << "Enter special skills. If no skills are present just press enter " << std::endl;
            std::cin.ignore();
            getline(std::cin,skill);
            std::cout << "Is that all? press y to finish ";
            std::cin >> y;
        }
    }

    void displayPetDetails() {

        std::cout << "Specie: " << specie << std::endl
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
            happy -= newhunger-hunger;
            hunger = newhunger;
            return;
        }
        hunger = newhunger;
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

    void list() {

        char end;
        std::cin.ignore();

        while(end != 'y') {

            std::string status,specie,id;
            int hunger,happy;

            std::cout << "Enter status of the adopted pet: ";
            getline(std::cin,status);

            std::cout << "Enter specie of the adopted pet: ";
            getline(std::cin,specie);

            std::cout << "Enter id of the adopted pet: ";
            getline(std::cin,id);

            std::cout << "Enter Hunger level of the adopted pet: ";
            std::cin >> hunger;

            std::cout << "Enter Happiness level of the adopted pet: ";
            std::cin >> happy;

            adoptedpetrecords.push_back(Pet(status,hunger,happy,specie,id));

            std::cout << "Is that all? press y to finish ";
            std::cin >> end;
        }
        return;

    }

    void adoptpet(std::vector<Pet> pets) {

        std::string status;
        std::string specie,id;
        int hunger,happy,check;
        std::cin.ignore();

        std::cout << "Enter id of the adopted pet: ";
        getline(std::cin,id);

        for (Pet element : pets) {

            if (element.id == id) {
                check = 1;
                break;
            }

        }

        if (check != 1) {
            std::cout << "Pet unavailable in stock" << std::endl;
            return;
        }

        std::cout << "Enter status of the adopted pet: ";
        getline(std::cin,status);

        std::cout << "Enter specie of the adopted pet: ";
        getline(std::cin,specie);

        std::cout << "Enter Hunger level of the adopted pet: ";
        std::cin >> hunger;

        std::cout << "Enter Happiness level of the adopted pet: ";
        std::cin >> happy;
        adoptedpetrecords.push_back(Pet(status,hunger,happy,specie,id));

    }

    void returnpet() {
        
        adoptedpetrecords.erase(adoptedpetrecords.begin());
        std::cout << "Pet returned" << std::endl;
        
    }

    void displayAdoptedpets() {

        for (Pet pets: adoptedpetrecords) {
            pets.displayPetDetails();
        }

    }

 };

 int main() {

    std::cout << "You will be entering pet(s) into stock first" <<std::endl;

    std::vector<Pet> pets;
    int choice;
    char end = 't';

    while (end != 'y') {
        std::string status,specie,id;
        int hunger,happy;

        std::cout << "Enter status of the pet in stock: ";
        std::cin.ignore();
        getline(std::cin,status);

        std::cout << "Enter specie of the pet in stock: ";
        getline(std::cin,specie);

        std::cout << "Enter id of the pet in stock: ";
        getline(std::cin,id);

        std::cout << "Enter Hunger level of the pet in stock: ";
        std::cin >> hunger;

        std::cout << "Enter Happiness level of the pet in stock: ";
        std::cin >> happy;
        pets.push_back(Pet(status,hunger,happy,specie,id));

        std::cout << "Is that all? press y to finish ";
        std::cin >> end; 
        
    }

    while (choice != 0) {
        std::cout << "1 -> Press if customer\n" << "2 -> Perform action on a pet in stock\n" << "0 -> End\n" << std::endl;
        std::cin >> choice;

        switch (choice) {

            case 1:
            {
            std::string name,mobilenum;
            int choic;

            std::cin.ignore();
            std::cout << "Enter name of the customer: ";
            getline(std::cin,name);

            std::cout << "Enter mobile number of the customer: ";
            getline(std::cin,mobilenum);

            Adopter customer(name,mobilenum);

            char fork;
            char ending;
            std::cout << "Does the customer have previous pets? y for yes: ";
            std::cin >> fork;

            if (fork == 'y') {
                customer.list();
            }

            while (ending != 'y') {
            std::cout << "1 -> Adopt new pet\n" << "2 -> Return Pet\n" << "3 -> Display owned pets\n" << std::endl;
            std::cin >> choic;

            switch (choic) {

                case 1:
                customer.adoptpet(pets);
                break;

                case 2:
                customer.returnpet();
                break;

                case 3:
                customer.displayAdoptedpets();
                break;

            } 
            
            std::cout << "Is that all? press y to finish ";
            std::cin >> ending; 
            } 
            
            }

            break;

            case 2:
            {
            std::string iid;
            std::cin.ignore();
            std::cout << "Enter id of the pet to be modified: ";
            getline(std::cin,iid);

            int choose;
            int check = 0;
            char ending;
            
            while (ending != 'y') {

            std::cout << "1 -> Update Happiness\n" << "2 -> Update Hunger\n" <<
             "3 -> Update Health status\n" << "4 -> Display details\n";
            std::cin >> choose;

            switch (choose) {

                case 1:
                {
                int happy;
                std::cout << "Enter new happiness: ";
                std::cin >> happy;

                for (Pet element : pets) {

                    if (element.id == iid) {
                        check = 1;
                        element.updateHappiness(happy);
                        break;
                    }
                }

                if (check != 1) {
                    std::cout << "Pet unavailable in stock" << std::endl;
                } }
                break;
                
                case 2:
                {
                int hungry;
                std::cout << "Enter new hungry: ";
                std::cin >> hungry;

                for (Pet element : pets) {

                if (element.id == iid) {
                    check = 1;
                    element.updateHunger(hungry);
                    break;
                }
            }

                if (check != 1) {
                    std::cout << "Pet unavailable in stock" << std::endl;
                } }
                break;
                
                case 3:
                {
                std::string status;
                std::cin.ignore();
                std::cout << "Enter new health status: ";
                getline(std::cin,status);

                for (Pet element : pets) {

                    if (element.id == iid) {
                        check = 1;
                        element.updateHealth(status);
                        break;
                    }
                }

                if (check != 1) {
                    std::cout << "Pet unavailable in stock" << std::endl;
                } }
                break;
        
                case 4:
                {
                for (Pet element : pets) {

                    if (element.id == iid) {
                        check = 1;
                        element.displayPetDetails();
                        break;
                    }
                }

                if (check != 1) {
                    std::cout << "Pet unavailable in stock" << std::endl;
                }
                }
                break;

            }

            std::cout << "Is that all? press y to finish ";
            std::cin >> ending;
            }
            }
            break;
        } 
    }  
}
