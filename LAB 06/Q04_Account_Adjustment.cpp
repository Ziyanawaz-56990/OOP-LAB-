#include <iostream>
using namespace std;

class AccountBalance {
private:
    double balance;

public:
    explicit AccountBalance(double b) : balance(b) {}

    AccountBalance operator-() const {
        return AccountBalance(-balance);
    }

    void display() const {
        cout << balance;
    }
};

int main() {
    double amount;
    cout << "Enter account balance: ";
    cin >> amount;

    AccountBalance original(amount);
    AccountBalance adjusted = -original;

    cout << "Original balance: "; original.display(); cout << '\n';
    cout << "Negated balance: "; adjusted.display(); cout << '\n';
    cout << "Original remains unchanged: "; original.display(); cout << '\n';
    return 0;
}
