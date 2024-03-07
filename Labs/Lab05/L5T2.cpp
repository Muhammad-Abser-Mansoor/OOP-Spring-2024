/* Programmer:Muhammad Abser Mansoor
 * Date: 01/03/2024
 * Descrption: loanhelper constant variable demonstration
 */

#include <iostream>
#include <vector>

class LoanHelper {
private:
    const float rate;  // Interest rate as a user-defined constant value
    float loanamount;
    int months;

public:
    // Constructor
    LoanHelper(float rate, float amount, int months)
        : rate(rate), loanamount(amount), months(months) {}

    // Function to calculate monthly loan payment

    void calculateLoanPayments() const {

        // Calculate monthly payment by dividing loan amount by number of months
        float monthlypayment = loanamount / months;

        float interest = monthlypayment * rate;
        float totalPayment = monthlypayment + interest;

        std::cout << "You have to pay " << totalPayment << " every month for "
                  << months << " months to repay your loan.\n";
    }
};

int main() {

    LoanHelper loanHelper(0.005,2000,12); // 0.005 = 0.5%

    loanHelper.calculateLoanPayments();

    return 0;
}
