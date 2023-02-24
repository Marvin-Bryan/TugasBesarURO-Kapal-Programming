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

const int MAP = 11;

int main() {
    
    srand(time(0)); // inisialisasi seed untuk generator bilangan acak

    int range = 11; // rentang 21 karena ada 21 bilangan bulat antara -10 sampai 10
    int randomNumber = rand() % range - 5;
    int x = randomNumber;
    int y = randomNumber;
    
    // membuat objek Ship
    Ship luffyShip(0, 0, 100, 5, 10);
    Ship enemyShip(x, y, 40, 5, 5);
    
    // print peta
    char map[MAP][MAP];
    
    for (int i = -10; i < MAP; i++) {
        for (int j = -10; j < MAP; j++) {
            map[i][j] = '~';
        }
    }
    
    map[0][0] = 'L';
    map[x][y] = 'E';
    
    for (int i = -10; i < MAP; i++) {
        for (int j = -10; j < MAP; j++) {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
    
    // menampilkan koordinat awal kapal
    luffyShip.printPosition();
    enemyShip.printPosition();

    // menyerang musuh
    luffyShip.attack();

    // menampilkan sisa health kapal
    cout << "Sisa health kapal: " << luffyShip.getHealth() << endl;

    return 0;
}
