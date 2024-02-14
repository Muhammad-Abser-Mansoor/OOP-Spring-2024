/*
 * Programmer: Muhammad Abser Mansoor 23K-0030
 * Date: 12/2/24
 * Desc: StationaryShop management class
 */

#include <iostream>
#include <string>

#include <iostream>
#include <string>

class StationaryShop {
private:
    std::string items[5];
    double prices[5];
    int itemCount;

public:
    // Constructor
    StationaryShop() : itemCount(0) {}

    // Adding items and their prices to the respective lists
    void addItem(std::string itemName, double price) {
        if (itemCount < 5) {
            items[itemCount] = itemName;
            prices[itemCount] = price;
            ++itemCount;
            std::cout << "Item added successfully." << std::endl;
        } else {
            std::cout << "Cannot add more items." << std::endl;
        }
    }

    // Getter
    void getItems() {
        std::cout << "Items available in the shop:" << std::endl;
        for (int i = 0; i < itemCount; ++i) {
            std::cout << items[i] << std::endl;
        }
    }

    // Modify the price of an item
    void modifyPrice(std::string itemName, double newPrice) {
        for (int i = 0; i < itemCount; ++i) {
            if (items[i] == itemName) {
                prices[i] = newPrice;
                std::cout << "Price of " << itemName << " modified to PKR " << newPrice << std::endl;
                return;
            }
        }
        std::cout << "Item not found." << std::endl;
        return;
    }

    // Display all items along with their prices
    void displayall() {
        std::cout << "Items available in the shop: " << std::endl;
        for (int i = 0; i < itemCount; ++i) {
            std::cout << items[i] << ": PKR " << prices[i] << std::endl;
        }
        return;
    }

    // Generate a receipt based on items and quantities bought by the customer
    void generateReceipt(std::string customerItems[], int quantities[], int itemCount) {
        double totalAmount = 0.0;
        std::cout << "\nReceipt:" << std::endl;
        for (int i = 0; i < itemCount; ++i) {
            std::string itemName = customerItems[i];
            int quantity = quantities[i];
            double itemPrice = 0.0;

            // Find the price of the item
            for (int j = 0; j < itemCount; ++j) {
                if (items[j] == itemName) {
                    itemPrice = prices[j];
                    break;
                }
            }

            // Calculate and display the subtotal for each item
            double subtotal = itemPrice * quantity;
            totalAmount += subtotal;
            std::cout << itemName << "x" << quantity << ": PKR " << subtotal << std::endl;
        }

        // Display the total amount
        std::cout << "Total Amount: PKR " << totalAmount << std::endl;
    }
};

int main() {
    StationaryShop shop;

    int choice;
    do {
        // Display menu
        std::cout << "\nStationary Shop Menu:" << std::endl;
        std::cout << "1. Add item and price" << std::endl;
        std::cout << "2. Retrieve list of items" << std::endl;
        std::cout << "3. Modify item price" << std::endl;
        std::cout << "4. Display items with prices" << std::endl;
        std::cout << "5. Generate receipt" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string itemName;
                double price;
                std::cout << "Enter item name: ";
                std::cin >> itemName;
                std::cout << "Enter item price: PKR ";
                std::cin >> price;
                shop.addItem(itemName, price);
                break;
            }
            case 2:
                shop.getItems();
                break;
            case 3: {
                std::string itemName;
                double newPrice;
                std::cout << "Enter item name to modify price: ";
                std::cin >> itemName;
                std::cout << "Enter new price: PKR ";
                std::cin >> newPrice;
                shop.modifyPrice(itemName, newPrice);
                break;
            }
            case 4:
                shop.displayall();
                break;
            case 5: {
                int itemCount;
                std::cout << "Enter the number of items bought by the customer: ";
                std::cin >> itemCount;

                std::string customerItems[5];
                int quantities[5];

                for (int i = 0; i < itemCount; ++i) {
                    std::cout << "Enter item name for item " << i + 1 << ": ";
                    std::cin >> customerItems[i];
                    std::cout << "Enter quantity for item " << i + 1 << ": ";
                    std::cin >> quantities[i];
                }

                shop.generateReceipt(customerItems, quantities, itemCount);
                break;
            }
            case 0:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }

    } while (choice != 0);

    return 0;
}
