#include <iostream>
using namespace std;
class Inventory;
class GameController{
public:
    void showInventory(Inventory &);
    void changeQuantity(Inventory &, int, int);
};
class Inventory {
    int playerId, n;
    int *quantity;
public:
    Inventory(int id, int items) {
        playerId = id;
        n = items;
        quantity = new int[n];
for (int i = 0; i < n; i++)
    quantity[i] = 0;
    }
void enter() {
for (int i = 0; i < n; i++) {
 cout << "Quantity of item " << i + 1 << ": ";
            cin >> quantity[i];
        }
    }
friend class GameController;
 ~Inventory() {
 delete[] quantity;
    }
};
void GameController::showInventory(Inventory &x) {
cout << "Player ID: " << x.playerId << "\n";
 cout << "Inventory: ";
for (int i = 0; i < x.n; i++)
 cout << x.quantity[i] << " ";
    cout << "\n";
}
void GameController::changeQuantity(Inventory &x, int pos, int value) {
    if (pos >= 1 && pos <= x.n)
        x.quantity[pos - 1] = value;
    else
        cout << "Invalid item position\n";
}
int main() {
    Inventory *bag = new Inventory(501, 4);
    bag->enter();
  GameController controller;
  controller.showInventory(*bag);
    controller.changeQuantity(*bag, 2, 10);
 cout << "After changing item 2:\n";
    controller.showInventory(*bag);
 delete bag;
return 0;
}