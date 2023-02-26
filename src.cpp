#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int range = 21;
char map[range][range];

void printMap() {
    for (int y=0; y<range; y++) {
        for (int x=0; x<range; x++) {
            cout << map[x][20-y];
        }
        cout << endl;
    }
}

class Ship {
private:
    int x;
    int y;
    int health;
    int maxAttackRange;
    int attackDamage;

public:
    char symbol;
    Ship(int startX, int startY, int startHealth, int startMaxAttackRange, int startAttackDamage, char startSymbol) {
        x = startX + 10;
        y = startY + 10;
        health = startHealth;
        maxAttackRange = startMaxAttackRange;
        attackDamage = startAttackDamage;
        symbol = startSymbol;
        map[x][y] = symbol;
    }

    int getX() {
        return x-10;
    }

    int getY() {
        return y-10;
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
                if (map[x][y+1] == '~') {
                    map[x][y+1] = map[x][y];
                    map[x][y] = '~';
                    y++;
                    break;
                } else {
                    cout << "Invalid direction" << endl;
                }
            case 'd':
                if (map[x][y-1] == '~') {
                    map[x][y-1] = map[x][y];
                    map[x][y] = '~';
                    y--;
                    break;
                } else {
                    cout << "Invalid direction" << endl;
                }
            case 'r':
                if (map[x+1][y] == '~') {
                    map[x+1][y] = map[x][y];
                    map[x][y] = '~';
                    x++;
                    break;
                } else {
                    cout << "Invalid direction" << endl;
                }
            case 'l':
                if (map[x-1][y] == '~') {
                    map[x-1][y] = map[x][y];
                    map[x][y] = '~';
                    x--;
                    break;
                } else {
                    cout << "Invalid direction" << endl;
                }
            default:
                break;
        }
    }

    void attack(Ship &other) {
        double distance = sqrt(pow(this->getX() - other.getX(), 2) + pow(this->getY() - other.getY(), 2));
        if (distance <= maxAttackRange) {
            other.takeDamage(attackDamage);
        } else {
            cout << "Enemy ship is out of range." << endl;
        }
    }

    void takeDamage(int damage) {
        health -= damage;
    }
};

int main() {
    srand(time(NULL));

    for (int i=0; i<range; i++) {
        for (int j=0; j<range; j++) {
            map[i][j] = '~';
        }
    }
    // initialize user's ship at position (0,0)
    Ship ship(0, 0, 100, 5, 100, 'U');

    // initialize enemy fleet at random positions
    vector<Ship> enemies;
    int p = 0;
    while (p < 5) {
        int x = rand() % 21;
        int y = rand() % 21;
        
        if (map[x][y] == '~') {
            Ship enemy(x-10, y-10, 50, 3, 5, 'E');
            enemies.push_back(enemy);
            p = p + 1;
        }
    }

    int numEnemiesDefeated = 0;

    while (ship.getHealth() > 0 && numEnemiesDefeated < 5) {
        // display user's ship position
        printMap();
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
            if (direction != 'u' && direction != 'd' && direction != 'r' && direction != 'l') {
                cout << "Invalid direction" << endl;
            } else {
                try {
                    ship.move(direction);
                }
                catch(exception& ex) {
                    cout << "Invalid direction" << endl;
                }
            }

        } else if (input == 'a') {
            // find an enemy ship within range and attack it
            bool foundTarget = false;
            for (Ship &enemy : enemies) {
                if (enemy.symbol == 'E') {
                    double distance = sqrt(pow(ship.getX() - enemy.getX(), 2) + pow(ship.getY() - enemy.getY(), 2));
                    if (distance <= ship.getMaxAttackRange()) {
                        ship.attack(enemy);
                        foundTarget = true;
                        if (enemy.getHealth() <= 0) {
                            numEnemiesDefeated++;
                            map[enemy.getX() +10][enemy.getY() +10] = '~';
                            enemy.symbol = 'X';
                            cout << "Ship defeated!" << endl;
                        }
                    }
                }
            }

            if (!foundTarget) {
                cout << "No target in range" << endl;
            }
        } else if (input == 's') {
            // do nothing
        } else {
            cout << "Invalid input" << endl;
        }

        char moveList[4] = {'u', 'r', 'l', 'd'};
        char inputList[3] = {'m', 'a', 's'};
        // move the enemy ships
        for (auto& enemy : enemies) {
            if (enemy.symbol == 'E') {
                char xyz = inputList[rand() % 3];
                if (xyz == 'm') {
                    enemy.move(moveList[rand() % 4]);
                } else if (xyz == 'a') {
                    double distance = sqrt(pow(ship.getX() - enemy.getX(), 2) + pow(ship.getY() - enemy.getY(), 2));
                    if (distance <= enemy.getMaxAttackRange()) {
                        enemy.attack(ship);
                        cout << "Ship hit by enemy! Health is now " << ship.getHealth() << endl;

                        // check if ship is defeated
                        if (ship.getHealth() <= 0) {
                            cout << "Ship defeated! Total opponents defeated: " << numEnemiesDefeated << endl;
                            break;
                        }
                    }
                } else {}   
            }
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
