/* Programmer:Muhammad Abser Mansoor
 * Date: 29/03/2024
 * Descrption: Game
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Player{

    int playerID;
    std::string playerName;
    int health;

    public:

    Player(int ID, std::string name) : playerID(ID) , playerName(name) , health(100) {}

    void sethealth(int health) { this->health = health; }
    int gethealth() { return this->health; }
};

class Weapon{

    std::string weaponsList[5];

    public:

    Weapon() {
        weaponsList[0] = "Kar98-K";
        weaponsList[1] = "Mosin-Nagant";
        weaponsList[2] = "M1 Garand";
        weaponsList[3] = "Sten Mk II";
        weaponsList[4] = "Carcano Modello 91/38";
    }

    std::string Use() {

        std::cout << "Which weapons will you use:-\n";
        for (int i = 0; i < 5;i++) {
            std::cout << i+1  << ".  " << weaponsList[i] << std::endl;
        }
        int choice;
        std::cin >> choice;

        return weaponsList[choice-1];
    }
};

class Enemy;

class Character : public Player{

    int level,points;
    std::string experience;

    public:

    Character(int id, std::string name) : Player(id,name), level(0) , points(0) , experience("Beginner") {}

    void LevelUp(int gains) {

        points += gains;

        level = points/10;

        if (level == 0) {

            experience = "Beginner";
        }

        else if (level == 1) {

            experience = "Intermediate";
        }

        else if (level == 2) {

            experience = "Advanced";
        }

        else {
            experience = "Expert";
        }
    }

    void playGame(Weapon weapons, Enemy& enemy);

    std::string getExperience() {return experience;}

};

class Enemy : public Player {

    int damage;

    public:

    Enemy(int id, std::string name, int damage) : Player(id, name), damage(damage) {
        
        if (damage > 10 || damage < 1) {
            damage = 5;
        }
    }

    void attack(Weapon weapons, Character& character) {

        std::cout << "Enemy\n";
        std::string weapon = weapons.Use();

        std::cout << "Enemy used " << weapon << std::endl;
        character.sethealth(character.gethealth()-damage);
    }
};

void Character::playGame(Weapon weapons, Enemy& enemy) {

    std::cout << "Character\n";
    std::string weapon = weapons.Use();

    std::cout << "Character used " << weapon << std::endl;
    enemy.sethealth(enemy.gethealth()-5);
    this->LevelUp(10);
}

int main() {

    Weapon weapons;

    Character character(0,"Hans");
    Enemy enemy(1,"Ivan", 50);

    for (int i = 0; i < 3;i++) {

        std::cout << "Character experience: " << character.getExperience() << "\n";
        std::cout << "Character health: " << character.gethealth() << "\n";
        character.playGame(weapons, enemy);
        std::cout << "Enemy health: " << enemy.gethealth() << "\n";
        enemy.attack(weapons, character);
    }

    std::cout << "Character experience: " << character.getExperience() << "\n";
}
