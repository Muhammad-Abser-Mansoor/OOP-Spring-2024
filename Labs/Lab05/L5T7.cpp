/* Programmer:Muhammad Abser Mansoor
 * Date: 01/03/2024
 * Descrption: Restaurant Ordering System
 */

#include <iostream>
#include <vector>

class MenuItem {
private:
    std::string foodName;
    double foodPrice;

public:
    MenuItem(std::string name, double price) : foodName(name), foodPrice(price) {}

    std::string getFoodName() {
        return foodName;
    }

    double getFoodPrice() {
        return foodPrice;
    }
};

class Menu {
private:
    std::vector<MenuItem> menuItems;

public:
    void addItem(MenuItem item) {
        menuItems.push_back(item);
    }

    void removeItem(int i) {
        menuItems.erase(next(menuItems.begin(), i));
    }

    void displayMenu() {
        std::cout << "Menu:\n";
        for (auto item : menuItems) {
            std::cout << item.getFoodName() << " - $" << item.getFoodPrice() << "\n";
        }
    }
};

class Payment {
private:
    double amount;

public:
    Payment(double amount) : amount(amount) {}

    double getAmount() {
        return amount;
    }
};

class Order {
private:
    std::vector<MenuItem> items;
    Payment payment;

public:
    Order(std::vector<MenuItem> orderItems, Payment orderPayment)
        : items(orderItems), payment(orderPayment) {}

    void displayOrder() {
        std::cout << "Order Details:\n";
        for (auto item : items) {
            std::cout << item.getFoodName() << " - $" << item.getFoodPrice() << "\n";
        }
        std::cout << "Total Amount: $" << payment.getAmount() << "\n";
    }
};

class RestaurantOrderingSystem {
private:
    Menu restaurantMenu;

public:
    void placeOrder(Order order) {
        // Process order logic
        order.displayOrder();
    }

    Menu getMenu() {
        return restaurantMenu;
    }
};

int main() {
    // Create menu items
    MenuItem item1("Burger", 8.99);
    MenuItem item2("Pizza", 12.99);

    // adding items
    Menu restaurantMenu;
    restaurantMenu.addItem(item1);
    restaurantMenu.addItem(item2);

    // Create a payment and an order
    Payment payment(21.98);
    Order customerOrder({item1, item2}, payment);

    // Create a restaurant ordering system
    RestaurantOrderingSystem restaurantSystem;

    // Display the menu
    restaurantSystem.getMenu().displayMenu();

    // Place an order
    restaurantSystem.placeOrder(customerOrder);

    return 0;
}
