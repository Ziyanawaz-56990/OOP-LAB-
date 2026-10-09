#include <iostream>
using namespace std;

class Bill {
private:
    int itemCount;
    double totalAmount;

public:
    Bill(int count = 0, double amount = 0.0)
        : itemCount(count), totalAmount(amount) {}

    Bill operator+(const Bill& other) const {
        return Bill(itemCount + other.itemCount,
                    totalAmount + other.totalAmount);
    }

    bool operator>(const Bill& other) const {
        return totalAmount > other.totalAmount;
    }

    void display() const {
        cout << "Items: " << itemCount
             << ", total amount: Rs. " << totalAmount;
    }
};

int main() {
    int count1, count2;
    double amount1, amount2;
    cout << "Enter first bill (number-of-items total-amount): ";
    cin >> count1 >> amount1;
    cout << "Enter second bill (number-of-items total-amount): ";
    cin >> count2 >> amount2;

    Bill a(count1, amount1), b(count2, amount2), combined = a + b;
    cout << "First bill: "; a.display(); cout << '\n';
    cout << "Second bill: "; b.display(); cout << '\n';
    cout << "Combined bill: "; combined.display(); cout << '\n';
    cout << "First bill > second bill by amount: "
         << (a > b ? "true" : "false") << '\n';
    return 0;
}
