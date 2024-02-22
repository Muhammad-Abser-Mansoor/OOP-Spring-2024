/* Programmer: Muhammad Abser Mansoor
 * Date: 22/2/2024
 * Desc.: Bank Account
 */

 #include <iostream>
 #include <string>
 #include <vector>

 class BankAccount {

    int accnumber;
    std::string accholder;
    double balance;

    public:

    BankAccount() {}

    BankAccount(int accnumber, std::string accholder, double balance) : 
    accnumber(accnumber), accholder(accholder), balance(balance) {}

    void deposit(double amount) {

        balance += amount;
        std::cout << amount <<" Deposited" << std::endl;

    }

    void withdraw(double amount) {

        if (balance - amount < 0) {

            std::cout << "Balance is insufficient" << std::endl;
            return;
        }

        balance -= amount;
        std::cout << amount << " Withdrawn" << std::endl;
    }

    void display() {

        std::cout << "Account Details are: \n" << "Account number: "
        << accnumber << std::endl << "Account Holder name: " << accholder 
        << std::endl << "Account Balance: " << balance << std::endl;
    }
 };

 int main() {

    std::vector<BankAccount> accounts;
    accounts.push_back(BankAccount(1,"Abser",500));
    accounts.push_back(BankAccount(2,"Fasih",0));

    for (int i = 0; i < 2;i++) {
        std::cout << std::endl;
        accounts[i].display();
        accounts[i].deposit(500);
        accounts[i].withdraw(1000);
    }
    return 0;
