/* Programmer:Muhammad Abser Mansoor
 * Date: 18/03/2024
 * Descrption: Banking system
 */

#include <iostream>
#include <vector>

class BankAccount {
    
    int accountId;
    double balance;
    int* transactionsHistory;
    int numTransactions;

    public:

    BankAccount(int id, double bal, int numT) : accountId(id) , balance(bal) , numTransactions(numT) {

        transactionsHistory = new int[numTransactions];
        for (int i = 0; i < numTransactions; i++) {

            int in;
            std::cout << "Enter transaction" << std::endl;
            std::cin >> in;
            transactionsHistory[i] = in;
        }
    }

    BankAccount(BankAccount &obj) : accountId(obj.accountId) , balance(obj.balance) , numTransactions(obj.numTransactions) {

        transactionsHistory = new int[numTransactions];
        for (int i = 0; i < numTransactions; i++) {

            transactionsHistory[i] = obj.transactionsHistory[i];
        }
    }

    void display() {

        std::cout << "Account ID: " << accountId << std::endl <<
        "Balance: " << balance << std::endl << "Transaction History:\n";

        for (int i = 0; i < numTransactions; i++) {

            std::cout << transactionsHistory[i] << std::endl;
        }

        std::cout << std::endl;
    }

    void updateTransactionHistory(int num) {

        delete[] transactionsHistory;
        numTransactions = num;
        transactionsHistory = new int[num];

        for (int i = 0; i < numTransactions; i++) {

            int in;
            std::cout << "Enter transaction" << std::endl;
            std::cin >> in;
            transactionsHistory[i] = in;
        }
    }

    ~BankAccount() {

        delete[] transactionsHistory;
    } 
};


int main() {

    BankAccount object1(4201, 2000, 4);
    BankAccount object2(object1);
    object1.display();
    object2.display();
    object1.updateTransactionHistory(2);
    object1.display();
    object2.display();
}
