#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Ship {
private:
    int x;
    int y;
    int health;
    int maxAttackRange;
    int attackDamage;
public:
    Ship(int startX, int startY, int startHealth, int startMaxAttackRange, int startAttackDamage) {
        x = startX;
        y = startY;
        health = startHealth;
        maxAttackRange = startMaxAttackRange;
        attackDamage = startAttackDamage;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    int getHealth() {
        return health;
    }

    int getMaxAttackRange() {
        return maxAttackRange;
    }

    int getAttackDamage() {
        return attackDamage;
    }

    void move(char direction) {
        switch(direction) {
            case 'u':
                y++;
                break;
            case 'd':
                y--;
                break;
            case 'r':
                x++;
                break;
            case 'l':
                x--;
                break;
            default:
                break;
        }
    }

    void attack(Ship &other) {
        double distance = sqrt(pow(x - other.getX(), 2) + pow(y - other.getY(), 2));
        if (distance <= maxAttackRange) {
            other.takeDamage(attackDamage);
        } else {
            cout << "Enemy ship is out of range." << endl;
        }
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health <= 0) {
            cout << "Ship defeated!" << endl;
        }
    }
};

int main() {
    srand(time(NULL));

    // initialize user's ship at position (0,0)
    Ship ship(0, 0, 100, 5, 10);

    // initialize enemy fleet at random positions
    vector<Ship> enemies;
    for (int i = 0; i < 5; i++) {
        int x = rand() % 10 + 1;
        int y = rand() % 10 + 1;
        Ship enemy(x, y, 50, 3, 5);
        enemies.push_back(enemy);
    }

    int numEnemiesDefeated = 0;

    while (ship.getHealth() > 0 && numEnemiesDefeated < 5) {
        // display user's ship position
        cout << "Ship position: (" << ship.getX() << ", " << ship.getY() << ")" << endl;

        // ask for user input
        char input;
        cout << "Enter 'm' to move, 'a' to attack, or 's' to stay put: ";
        cin >> input;

        if (input == 'm') {
            // ask player for direction of movement
            cout << "Enter 'u' to move up, 'd' to move down, 'r' to move right, or 'l' to move left: ";
            char direction;
            cin >> direction;
            ship.move(direction);
        } else if (input == 'a') {
            // find an enemy ship within range and attack it
            bool foundTarget = false;
            for (Ship &enemy : enemies) {
                double distance = sqrt(pow(ship.getX() - enemy.getX(), 2) + pow(ship.getY() - enemy.getY(), 2));
                if (distance <= ship.getMaxAttackRange()) {
                    ship.attack(enemy);
                    foundTarget;
                    ship.attack(enemy);
                    foundTarget = true;
                    break;
                }
            }

            if (!foundTarget) {
                cout << "No target in range" << endl;
            }
        } else if (input == 'm') {
            // ask player for direction of movement
            cout << "Enter 'u' to move up, 'd' to move down, 'l' to move left, or 'r' to move right: ";
            char direction;
            cin >> direction;

            // move the ship
            if (direction == ('u' || 'd' || 'l' || 'r')) {
                ship.move(direction);
            } else {
                cout << "Invalid direction" << endl;
            }
        } else if (input == 's') {
            // do nothing
        } else {
            cout << "Invalid input" << endl;
        }

        // move the enemy ships
        for (auto& enemy : enemies) {
            enemy.move('d'); // Ini maunya musuh dibuat bergerak ke arah random, cuman gw blom nemu caranya
            if ((((enemy.getY() - ship.getY()) == 0) && ((enemy.getX() - ship.getX()))) == 0) {
                ship.takeDamage(5);
                enemy.takeDamage(5);
                cout << "Ship hit by enemy! Health is now " << ship.getHealth() << endl;
            }
        }

        // check if ship is defeated
        if (ship.getHealth() <= 0) {
            cout << "Ship defeated! Total opponents defeated: " << numEnemiesDefeated << endl;
            break;
        }

        // check if all enemies are defeated
        bool allEnemiesDefeated = true;
        for (auto& enemy : enemies) {
            if (enemy.getHealth() > 0) {
                allEnemiesDefeated = false;
                break;
            }
        }
        if (allEnemiesDefeated) {
            cout << "All enemies defeated! Total opponents defeated: " << numEnemiesDefeated << endl;
            break;
        }
    }

    return 0;
}
