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
    
    void takeDamage(int damage) {
        health -= damage;
        if (health <= 0) {
            cout << "Ship defeated!" << endl;
        }
    }    
};
