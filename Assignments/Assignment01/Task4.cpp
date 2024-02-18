/* Programmer: Muhammad Abser Mansoor
 * Date: 18/2/2024
 * Desc.: Rollercoaster Class
 */

#include <iostream>
#include <string>
#include <vector>

class RollerCoaster {

    std::string name;
    int height;
    int length;
    int speed;
    int capacity;
    int CurrentNumRiders;
    bool RideInProgress;

    public:

    RollerCoaster() : name("roller coaster") , height(500) , length(2000) , speed(0) ,
                      capacity(20) , CurrentNumRiders(0) , RideInProgress(false) {}
    
    RollerCoaster(std::string newname, int newheight, int newlength, int newspeed, int newcapacity, int newCurrentNumRiders) : 
                    name(newname) , height(newheight) , length(newlength) , speed(0) ,
                    CurrentNumRiders(newCurrentNumRiders) , RideInProgress(false) {
        
        if (newcapacity > 3) {

            (newcapacity % 2 == 0 || newcapacity % 3 == 0) ? capacity = newcapacity : capacity = 2 * (newcapacity / 2);
        }
    }

    std::string getname() {
        return name;
    }

    int getheight() {
        return height;
    }

    int getlength() {
        return length;
    }

    int getspeed() {
        return speed;
    }

    int getcapacity() {
        return capacity;
    }

    int getCurrentNumRiders() {
        return CurrentNumRiders;
    }
    
    bool getRideInProgress() {
        return RideInProgress;
    }

    void setname(std::string newname) {
        name = newname;
    }

    void setheight(int newheight) {
        height = newheight;
    }

    void setlength(int newlength) {
        length = newlength;
    }

    void setcapacity(int newcapacity) {

        if (newcapacity > 3) {

            (newcapacity % 2 == 0 || newcapacity % 3 == 0) ? capacity = newcapacity : capacity = 2 * (newcapacity / 2);
        }
    }

    int Seating(int passengers) {

        if (RideInProgress) {
            return -1;
        }

        if (passengers > capacity) {

            CurrentNumRiders = capacity;
            return passengers - capacity;

        }
        else {

            CurrentNumRiders = passengers;
            return 0;
        }
    }

    int RideStart() {

        if (RideInProgress) {
            return -1;
        }
        RideInProgress = true;
        return capacity - CurrentNumRiders;
    }

    void RideHalt() {

        if (RideInProgress) {

            RideInProgress = false;
            speed = 0;
            std::cout << "Ride Halted" << std::endl;
            return;
        }
    }

    void Unload() {

        if (RideInProgress) {
            std::cout << "Ride is currently in progress please come again later" << std::endl;
            return;
        }

        CurrentNumRiders = 0;
    }

    void IncreaseSpeed(std::string Rollnum) {
        for (int i = Rollnum.length()-1;i >= 0;i--) {
            
            int changeinspeed = Rollnum[i] - '0';
            if (changeinspeed > 0 && changeinspeed < 10) {
                speed += Rollnum[i] - '0';
                std::cout << "Speed increased by " << Rollnum[i] - '0' << std::endl;
                return;
            }
        }
    }

    void DecreaseSpeed(std::string Rollnum) {
    for (int i = 0;i < Rollnum.length();i++) {
            
            int changeinspeed = Rollnum[i] - '0';
            if (changeinspeed > 0 && changeinspeed < 10) {
                speed -= Rollnum[i] - '0';
                std::cout << "Speed decreased by " << Rollnum[i] - '0' << std::endl;
                return;
            }
        }
    }
};

int main() {

    RollerCoaster RC1;
    RollerCoaster RC2("Better Coaster", 400, 1000, 0, 40, 0);

    std::cout << RC2.getname() << std::endl;
    std::cout << RC2.getlength() << std::endl;
    std::cout << RC2.getheight() << std::endl;
    std::cout << RC2.getspeed() << std::endl;
    std::cout << RC2.getcapacity() << std::endl;
    std::cout << RC2.getCurrentNumRiders() << std::endl;
    std::cout << RC2.getRideInProgress() << std::endl;

    RC2.setname("Even Better Coaster");
    RC2.setheight(500);
    RC2.setlength(1500);
    RC2.setcapacity(70);

    std::cout << RC2.Seating(50) << " people have to wait for next ride" << std::endl;
    std::cout << RC2.RideStart() << " seats are empty" << std::endl;
    RC2.IncreaseSpeed("0030");
    RC2.DecreaseSpeed("0030");
    RC2.RideHalt();
    RC2.Unload();

    std::cout << RC2.getname() << std::endl;
    std::cout << RC2.getlength() << std::endl;
    std::cout << RC2.getheight() << std::endl;
    std::cout << RC2.getspeed() << std::endl;
    std::cout << RC2.getcapacity() << std::endl;
    std::cout << RC2.getCurrentNumRiders() << std::endl;
    std::cout << RC2.getRideInProgress() << std::endl;

}
    
