/* Programmer: Muhammad Abser Mansoor
 * Date: 15/2/2024
 * Desc.: FAST Tables
 */

 #include <iostream>
 #include <string>
 #include <vector>

 #define MAX_TABLES 5

 class Table{
    
    const int totalseats;
    int occupied;
    int free;
    bool clean;

    public:

    Table() {
        totalseats = 4;
        occupied = 0;
        free = 4;
        clean = true;
    }

    Table(int Total) : totalseats(Total < 6 ? 4 : 8), clean(true), occupied(0), free(totalseats) {}

    void Seating(int people) {

        occupied += people;
        free = totalseats - occupied;

    }

    void CleanTable() {

        clean = true;
    }

    void Eat(bool eaten) {

        if (eaten) clean = false;
    }
};

 int OccupyTable(std::vector<Table> tables, int people) {

        int i = 0;
        for (Table element : tables) {

            if (element.clean) {

                element.totalseats >= people ? element.Seating(people) : continue;
                return i;

            }
        }
        std::cout << "No suitable table could be found" << std::endl;
    }

 void EmptyTable(int tablenumber, std::vector<Table> tables) {

        tables[tablenumber].occupied = 0;
        tables[tablenumber].free = totalseats;

    }

int main() {

    std::vector<Table> tables;
    auto it = tables.begin(); // Iterator
    int total;

    while (it != tables.end()) {

        std::cout << "Enter Capacity: " << std::endl;
        std::cin >> total;

        tables.push_back(Table(total));
        it++;
        
    }
    int table1 = OccupyTable(tables,4); // Occupying Table 1
    int table2 = OccupyTable(tables,6); // Occupying Table 2

    tables[table1].Eat(false); // Using the table
    tables[table1].Eat(true); // Having lunch on the table
    tables[table1].CleanTable(true); // Cleaning the table

    EmptyTable(table1,tables); // Leaving the table
    EmptyTable(table2,tables); // Emptying table 2
}

