/* Programmer:Muhammad Abser Mansoor
 * Date: 18/03/2024
 * Descrption: Library management
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Character {

    int health, damage;

    public:

    Character(int health, int damage) : health(health) , damage(damage) {}

    void display() {
        std::cout << "Health: " << health << std::endl << "Damage: " << damage << std::endl;
    }
};

class Enemy : public Character {

    public:

    Enemy(int health, int damage) : Character(health,damage) {}

    void display() {
        std::cout << "Enemy stats:\n";
        Character::display();
    }
};

class Player : public Character {

    public:

    Player(int health, int damage) : Character(health,damage) {}

    void display() {
        Character::display();
    }
};

class Wizard : public Player {

    int magic_power;
    std::string spells;

    public:

    Wizard(int health, int damage, int mp, std::string spell) : Player(health,damage) , magic_power(mp) , spells(spell) {}
    
    void display() {
        
        std::cout << "Wizard stats:\n" << "Magic Power: " << magic_power << std::endl << "Spells: " << spells << std::endl;
        Player::display();
    }
};

int main() {

    Wizard Gandalf(400,100,600,"Law of Regression");
    Gandalf.display();
}
