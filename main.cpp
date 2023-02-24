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
    
    void moveRight() {
        x += 1;
    }
    
    void moveLeft() {
        x -= 1;
    }
    
    void moveDown() {
        y -= 1;
    }
    
    void moveUp() {
        y += 1;
    }
    
    void printPosition() {
        cout << "Kapal berada di koordinat (" << x << "," << y << ")" << endl;
    }
    
    void attack() {
        //tolong diisi
    }
    
    void takeDamage(int damage) {
        health -= damage;
        if (health <= 0) {
            cout << "Ship defeated!" << endl;
        }
    }
    
    int getHealth() {
        return health;    
    }
};

int main() {
    // membuat objek Ship
    Ship luffyShip(0, 0, 100, 10, 20);

    // menampilkan koordinat awal kapal
    luffyShip.printPosition();

    // menyerang musuh
    luffyShip.attack();

    // menampilkan sisa health kapal
    cout << "Sisa health kapal: " << luffyShip.getHealth() << endl;

    return 0;
}
