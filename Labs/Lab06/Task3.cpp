/* Programmer:Muhammad Abser Mansoor
 * Date: 18/03/2024
 * Descrption: Salon appointments tracking
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Appointment {

    int mintime;
    double cost;

    public:

    static int totalappointments;
    static double earnings;

    Appointment(int minutes, double payment) : mintime(minutes) , cost(payment) {

        Appointment::totalappointments += 1;
        Appointment::earnings += payment;
    }

    double getCost() { return cost; }
    double getMinTime() { return mintime; }

    static double getAverageCost() { return Appointment::earnings/Appointment::totalappointments; }
};

double Appointment::earnings = 0.f;
int Appointment::totalappointments = 0;

int main() {
    Appointment first(60, 3);
    std::cout << first.getMinTime() << " Minutes : $" << first.getCost() << "\n";
    Appointment second(90, 4);
    std::cout << second.getMinTime() << " Minutes : $" << second.getCost() << "\n";
    Appointment third(120, 5);
    std::cout << third.getMinTime() << " Minutes : $" << third.getCost() << "\n";
    Appointment fourth(180, 7);
    std::cout << fourth.getMinTime() << " Minutes : $" << fourth.getCost() << "\n";

    std::cout << Appointment::getAverageCost() << std::endl;

    return 0;
}
