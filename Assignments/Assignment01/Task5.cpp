/* Programmer: Muhammad Abser Mansoor
 * Date: 15/2/2024
 * Desc.: Restaurant Coupons
 */

 #include <iostream>
 #include <string>
 #include <vector>

const int now = 8;

class Restaurant {
public:
    std::string name, location;
    std::vector<std::string> menu, validcouponcodes;
    std::vector<float> prices;
    static int couponsredeemed;
    std::string code;

    std::vector<int> bill; // stores indices of purchased items
    float total;

    Restaurant(std::string newname, std::string newlocation, std::string newcode, std::vector<std::string> newmenu, std::vector<float> newprices) 
    : name(newname), location(newlocation), code(newcode), menu(newmenu), prices(newprices), total(0)  {}

    void display_menu() {
        for (int i = 0; i < menu.size(); i++) {
            std::cout << i+1 << "- " <<  menu[i] << " - $" << prices[i] << std::endl; 
        }

        std::cout << "\n";
    }

    void generate_bill() {
        for (int i : bill) {
            std::cout << i+1 << "- " <<  menu[i] << " - $" << prices[i] << std::endl;
            total += prices[i];
        }

        std::cout << "Total: $" << total << std::endl;
    }

    void apply_discount() {

        int count = 0;

        for (int i : bill) {

            for (int j : bill) {
                if (i == j) count++;
            }

            if (count >= 2) {
                std::cout << "Discounted: $" << total - prices[i] << std::endl;
                return;
            }
        }
    }
};

int Restaurant::couponsredeemed = 0;

class BOGOCoupon {
public:
    std::string couponcode, restaurantcode;
    int valid_from, valid_until;

    BOGOCoupon(std::string code, std::string rescode, int from, int until)
    : couponcode(code), restaurantcode(rescode), valid_until(until), valid_from(from) {}

    bool is_valid(std::string rescode) {

        if (rescode != restaurantcode && now >= valid_from && now <= valid_until) {

            return false;
        }
        return true;
    }
};

class User {
public:
    std::string name, mobilenumber;
    int age;
    std::vector<BOGOCoupon> coupons, redeemedcoupons;

    User(std::string newname, std::string phone, int newage) : name(newname), mobilenumber(phone), age(newage) {}

    void accumulate_coupon(BOGOCoupon coupon) { coupons.push_back(coupon); }

    bool is_redeemed(BOGOCoupon coupon) {

        for (BOGOCoupon redeemed : redeemedcoupons) {

            if (coupon.couponcode == redeemed.couponcode) return true;
        }

        return false;
    }

    int has_valid_coupon(std::string rescode) {

        for (int i = 0; i < coupons.size(); i++) {
            if (!is_redeemed(coupons[i]) && coupons[i].is_valid(rescode)) return i;
        }

        return -1;
    }

    bool redeem_coupon(int coupon, std::string rescode) {

        if (!is_redeemed(coupons[coupon]) && coupons[coupon].is_valid(rescode)) {
            redeemedcoupons.push_back(coupons[coupon]);
            return true;
        }

        return false;
    }
};

void menu() {
    std::cout << "1. Menus\n"
         << "2. Receipt\n"
         << "3. Add Item\n"
         << "4. Exit Menu\n"
         << ">> ";
}

void get_receipt(User &user, Restaurant &res) {
    int index = user.has_valid_coupon(res.code);

    std::cout << "Coupon available" << std::endl;
    std::cout << user.coupons[index].restaurantcode << "-BOGO-" << user.coupons[index].couponcode << std::endl;
    std::cout << "Would you like to avail? (y/n): ";
    char choice;
    std::cin >> choice;

    if (choice == 'n') {
        res.generate_bill();
        return;
    }

    res.generate_bill();
    res.apply_discount();
    res.bill.clear();
}

User create_user() {
    char name[100], phone[100];
    int age;

    std::cout << "Enter user name: ";
    std::cin.getline(name, 100);

    std::cout << "Enter user phone number: ";
    std::cin.getline(phone, 100);

    std::cout << "Enter user age: ";
    std::cin >> age;

    return { name, phone, age };
}

int main()
{
    Restaurant fh("Food Haven", "City Center", "FH",
        { "Sushi", "Pad Thai", "Mango Tango" },
        { 5.99, 9.99, 3.69 }
    );
    Restaurant pb("Pixel Bites", "Cyber Street", "PB",
        { "Binary Burger", "Quantum Quinoa", "Data Donuts" },
        { 5.99, 12.99, 6.99 }
    );

    User user = create_user();
    user.accumulate_coupon(BOGOCoupon("12345", "FH", 0, 30));
    user.accumulate_coupon(BOGOCoupon("33367", "PB", 0, 30));

    bool flag = true;
    while(flag) {
        int choice;
        menu();
        std::cin >> choice;

        int res;
        switch(choice) {
        case 1:
            std::cout << "Select restaurant\n"
                 << "1. Food Haven\n"
                 << "2. Pixel Bites\n"
                 << ">> ";
            std::cin >> res;

            if (res == 1) fh.display_menu();
            else if (res == 2) pb.display_menu();
            break;
        case 2:
            std::cout << "Select restaurant\n"
                 << "1. Food Haven\n"
                 << "2. Pixel Bites\n"
                 << ">> ";
            std::cin >> res;

            if (res == 1) get_receipt(user, fh);
            else if (res == 2) get_receipt(user, pb);

            break;
        case 3:
            std::cout << "Select restaurant\n"
                 << "1. Food Haven\n"
                 << "2. Pixel Bites\n"
                 << ">> ";
            std::cin >> res;

            int item;
            std::cout << "Enter item number: ";
            std::cin >> item;

            if (res == 1) fh.bill.push_back(item);
            else if (res == 2) fh.bill.push_back(item);

            break;
        case 4:
            flag = false;
            break;
        default:
            std::cout << "Incorrect option" << std::endl;
        }
    }

    return 0;
}
