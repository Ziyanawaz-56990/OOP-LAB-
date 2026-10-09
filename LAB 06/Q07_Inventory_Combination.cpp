#include <iostream>
#include <string>
using namespace std;

class InventoryItem {
private:
    int productId, quantity;
    double unitPrice;

public:
    InventoryItem(int id, double price, int qty)
        : productId(id), quantity(qty), unitPrice(price) {}

    // Compatible items combine; incompatible items are reported by main.
    bool isCompatible(const InventoryItem& other) const {
        return productId == other.productId && unitPrice == other.unitPrice;
    }

    InventoryItem operator+(const InventoryItem& other) const {
        if (!isCompatible(other))
            throw invalid_argument("Cannot combine items: product IDs or unit prices differ.");
        return InventoryItem(productId, unitPrice, quantity + other.quantity);
    }

    void display() const {
        cout << "Product ID: " << productId
             << ", unit price: Rs. " << unitPrice
             << ", quantity: " << quantity;
    }
};

int main() {
    int id1, qty1, id2, qty2;
    double price1, price2;
    cout << "Enter first item (product ID unit-price quantity): ";
    cin >> id1 >> price1 >> qty1;
    cout << "Enter second item (product ID unit-price quantity): ";
    cin >> id2 >> price2 >> qty2;

    InventoryItem a(id1, price1, qty1), b(id2, price2, qty2);
    cout << "First item: "; a.display(); cout << '\n';
    cout << "Second item: "; b.display(); cout << '\n';

    try {
        InventoryItem combined = a + b;
        cout << "Combined item: "; combined.display(); cout << '\n';
    } catch (const exception& e) {
        cout << "Combination failed: " << e.what() << '\n';
    }

    cout << "Original first item after operation: "; a.display(); cout << '\n';
    cout << "Original second item after operation: "; b.display(); cout << '\n';
    return 0;
}
