/* Programmer:Muhammad Abser Mansoor
 * Date: 18/03/2024
 * Descrption: Cricketer statistics
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

inline double strikerate(int runs, int balls) { return runs/balls * 100; }
inline double average(int runs, int outs) { return runs/outs; }

int main() {
    int balls, runs, outs;
    std::cout << "Enter number of balls: ";
    std::cin >> balls;
    std::cout << "Enter number of runs: ";
    std::cin >> runs;
    std::cout << "Enter number of outs: ";
    std::cin >> outs;

    std::cout << "Strike rate: " << strikerate(runs, balls) << "\n";
    std::cout << "Batting average: " << average(runs, outs) << std::endl;

    return 0;
}
