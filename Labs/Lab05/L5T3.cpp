/* Programmer:Muhammad Abser Mansoor
 * Date: 01/03/2024
 * Descrption: Check strings for characters that are not alphabets
 */

#include <iostream>
#include <vector>
#include <cctype>

class ValidateString {
private:
    std::string input;

public:
    //Constructor
    ValidateString(std::string str) : input(str) {}

    // Constant function
    bool isValid() const {
        for (char ch : input) {
            if (!isalpha(ch)) {
                return false;  // If any character is not an alphabet, the string is invalid
            }
        }
        return true;  // All characters are alphabets, the string is valid
    }
};

int main() {

    ValidateString String1("HelloWorld");
    ValidateString String2("Hello123");

    //Perform tests
    std::cout << "Is 'HelloWorld' valid? " << (String1.isValid() ? "Yes" : "No") << std::endl;
    std::cout << "Is 'Hello123' valid? " << (String2.isValid() ? "Yes" : "No") << std::endl;

    return 0;
}
