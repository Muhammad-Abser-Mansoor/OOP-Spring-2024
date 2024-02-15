/* Programmer: Muhammad Abser Mansoor
 * Date: 15/2/2024
 * Desc.: Weekdays class
 */

 #include <iostream>
 #include <string>
 #include <vector>

 class WeekDays {

    std::string days[7];
    int curday;

    WeekDays() {

     days[0] = "Sunday";
     days[1] = "Monday";  
     days[2] = "Tuesday";  
     days[3] = "Wednesday";  
     days[4] = "Thursday";  
     days[5] = "Friday";  
     days[6] = "Saturday";     

    }

    WeekDays(int cur) {

        if (cur > 6) {
            cur = cur % 7;
        }
        curday = cur;
    }

    std::string getCurrentDay() {

        return days[curday-1];
    }

    std::string getNextDay() {

        if (curday == 7) {
            return days[0];
        }

        return days[curday];
    }

    std::string getPreviousDay() {

        if (curday == 1) {
            return days[6];
        }

        return days[curday-2];
    }

    std::string getNthDayFromToday(int n) {

        if (n+curday > 7) {
            curday = (n+curday) % 7;
            return days[curday-1];
        }

        else {
            return days[curday-1];
        }
    }
 };

 int main() {

    WeekDays weekday;



 }
