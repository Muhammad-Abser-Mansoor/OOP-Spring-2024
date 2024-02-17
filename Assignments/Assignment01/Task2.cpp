/* Programmer: Muhammad Abser Mansoor
 * Date: 15/2/2024
 * Desc.: Pet shop database
 */

 #include <iostream>
 #include <string>
 #include <vector>

 #define MAX_TABLES 5

 class Table{

    public:

    const int totalseats;
    int occupied;
    int free;
    bool clean;

    Table() : totalseats(4) {

        occupied = 0;
        free = 4;
        clean = true;
    }

    Table(int Total) : totalseats(Total < 6 ? 4 : 8), clean(true), occupied(0), free(totalseats) {}

    void Seating(int people) {

        occupied += people;
        free = totalseats - occupied;
        std::cout << "Table occupied by " << occupied << " people" << std::endl;

    }

    void CleanTable() {

        clean = true;
        std::cout << "Table cleaned" << std::endl;
        return;
    }

    void Eat(bool eaten) {

        if (eaten) { 
            clean = false;
            std::cout << "Lunch Eaten" << std::endl;
        }
        else {
            std::cout << "Lunch not eaten" << std::endl;
        }
        return;
    }
};

 int OccupyTable(std::vector<Table> tables, int people) {

        int i = 0;
        for (Table element : tables) {

            if (element.clean) {

                if (element.totalseats >= people) {
                    element.Seating(people);
                    return i;
                }
            }
            i++;
        }
        std::cout << "No suitable table could be found" << std::endl;
        return -1;
    }

 void EmptyTable(int tablenumber, std::vector<Table> tables) {

        tables[tablenumber].occupied = 0;
        tables[tablenumber].free = tables[tablenumber].totalseats;
        std::cout << "Table emptied" << std::endl;

    }

int main() {

    std::vector<Table> tables;
    int it = 0; // Iterator
    int total;

    while (it < 5) {

        std::cout << "Enter Capacity: ";
        std::cin >> total;

        tables.push_back(Table(total));
        it++;
        
    }
    int table1 = OccupyTable(tables,4); // Occupying Table 1
    int table2 = OccupyTable(tables,6); // Occupying Table 2

    tables[table1].Eat(false); // Using the table
    tables[table1].Eat(true); // Having lunch on the table
    tables[table1].CleanTable(); // Cleaning the table

    EmptyTable(table1,tables); // Leaving the table
    EmptyTable(table2,tables); // Emptying table 2
}

