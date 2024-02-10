/*
 * Programmer: Muhammad Abser Mansoor 23K-0030
 * Date: 10/2/24
 * Desc: Calendar shenanigans
 */

#include <iostream>
#include <map>
#include <string>

class Calendar {

    bool leap;
    std::string jan[31];
    std::string feb[29];
    std::string mar[31];
    std::string apr[30];
    std::string may[31];
    std::string jun[30];
    std::string jul[31];
    std::string aug[31];
    std::string sep[30];
    std::string oct[31];
    std::string nov[30];
    std::string dec[31];

    // Creating a map to access the arrays based on string inputs
    std::map<std::string, std::string*> monthArrays;

    public:

    Calendar() {
    
    monthArrays["january"] = jan;
    monthArrays["february"] = feb;
    monthArrays["march"] = mar;
    monthArrays["april"] = apr;
    monthArrays["may"] = may;
    monthArrays["june"] = jun;
    monthArrays["july"] = jul;
    monthArrays["august"] = aug;
    monthArrays["september"] = sep;
    monthArrays["october"] = oct;
    monthArrays["november"] = nov;
    monthArrays["december"] = dec; }
    // Map to be used in methods

    void add(int date, std::string month, std::string task) {

        if (monthArrays.find(month) != monthArrays.end()) {

            std::string *mon = monthArrays[month]; // Now we can use the correct array
            mon[date] = task;

        }
        return;
    }

    void remove(int date, std::string month) {

        if (monthArrays.find(month) != monthArrays.end()) {

            std::string *mon = monthArrays[month]; // Now we can use the correct array
            mon[date] = "";

        }
        return;
    }

    void display(bool isleap) {
        // Displaying 12 months
        if (isleap) {
            displaymonth("january",jan,31);
            displaymonth("february",feb,28);
            displaymonth("march",mar,31);
            displaymonth("april",apr,30);
            displaymonth("may",may,31);
            displaymonth("june",jun,30);
            displaymonth("july",jul,31);
            displaymonth("august",aug,31);
            displaymonth("september",sep,30);
            displaymonth("october",oct,31);
            displaymonth("november",nov,30);
            displaymonth("december",dec,31);
        }
        else {
            displaymonth("january",jan,31);
            displaymonth("february",feb,29);
            displaymonth("march",mar,31);
            displaymonth("april",apr,30);
            displaymonth("may",may,31);
            displaymonth("june",jun,30);
            displaymonth("july",jul,31);
            displaymonth("august",aug,31);
            displaymonth("september",sep,30);
            displaymonth("october",oct,31);
            displaymonth("november",nov,30);
            displaymonth("december",dec,31);
        }
    return;
    }

    void displaymonth(std::string month,std::string *mon,int dates) {
        // Displaying each month
        std::cout << month << ";" << std::endl;

        for (int i = 0; i < dates; i++) {
            if (mon[i] != "") {
                std::cout << i << " : " << mon[i] << std::endl;
            }
        }
    }
};

int main() {

    std::string month,task;
    char choice,end;
    int date;
    bool isleap;
    std::cout << "Is the year a leap year? 1 for yes or 0 for no ";
    std::cin >> isleap;
    Calendar cal;

    for (;;) {
        
        std::cout << "Enter a to add tasks, r for removal and d to display: ";
        std::cin >> choice;
        switch (choice) {
            case 'a':

            std::cout << "Enter the date at which task is to be added: ";
            std::cin >> date;
            std::cout << "Enter the month at which task is to be added: ";
            std::cin.ignore();
            getline(std::cin,month);
            std::cout << "Enter the task: ";
            std::cin.ignore();
            getline(std::cin,task);
            cal.add(date,month,task);
            break;

            case 'r':

            std::cout << "Enter the date at which task is to be removed: ";
            std::cin >> date;
            std::cout << "Enter the month at which task is to be removed: ";
            std::cin.ignore();
            getline(std::cin,month);
            cal.remove(date,month);
            break;

            case 'd':
            cal.display(isleap);
            break;

            default:
            std::cout << "Incorrect input" << std::endl;
        }

        std::cout << "Is that all? y or n";
        std::cin >> end;
        if (end == 'y') {
            return 0;
        }
    }
}
