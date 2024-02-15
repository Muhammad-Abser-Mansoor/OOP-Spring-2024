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
    int happy;     // Attributes
    std::vector<std::string> ss;

    public:

    Pet() { // Constructor
        hstatus = "Healthy";
        hunger = 0;
        happy = 10;
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

        std::cout << "Health Status: " << hstatus
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

        if (happy < 10 && hungry < newhunger) {

            
            hungry = newhunger;
        }
    }
 };
