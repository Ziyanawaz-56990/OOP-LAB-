#include <iostream>
using namespace std;

class GameController; // forward declaration

class Inventory {
private:
    int playerID;
    int numItems;
    int *itemQuantities;

    // GameController is granted access to private members
    friend class GameController;

public:
    Inventory(int id, int count) {
        playerID = id;
        numItems = count;
        itemQuantities = new int[numItems];
        for (int i = 0; i < numItems; i++)
            itemQuantities[i] = 0;
    }

    ~Inventory() {
        delete[] itemQuantities;
    }
};

class GameController {
public:
    void setItemQuantity(Inventory &inv, int itemIndex, int quantity) {
        if (itemIndex < 0 || itemIndex >= inv.numItems) {
            cout << "Invalid item index." << endl;
            return;
        }
        inv.itemQuantities[itemIndex] = quantity;
    }

    void displayInventory(const Inventory &inv) {
        cout << "Player " << inv.playerID << " inventory: ";
        for (int i = 0; i < inv.numItems; i++)
            cout << "[Item " << i << ": " << inv.itemQuantities[i] << "] ";
        cout << endl;
    }
};

int main() {
    int id, itemCount;
    cout << "Enter player ID: ";
    cin >> id;
    cout << "Enter number of item types: ";
    cin >> itemCount;

    Inventory *inv = new Inventory(id, itemCount);
    GameController controller;

    controller.displayInventory(*inv);

    // Controller modifies private inventory data without it being public
    for (int i = 0; i < itemCount; i++) {
        int qty;
        cout << "Enter quantity for item " << i << ": ";
        cin >> qty;
        controller.setItemQuantity(*inv, i, qty);
    }

    cout << "\nAfter updates:\n";
    controller.displayInventory(*inv);

    delete inv;
    return 0;
}
