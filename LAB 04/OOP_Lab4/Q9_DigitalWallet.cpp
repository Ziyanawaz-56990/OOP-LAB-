#include <iostream>
#include <string>
using namespace std;

class WalletManager; // forward declaration

class DigitalWallet {
private:
    string userName;
    double walletBalance;
    bool walletStatus; // true = active, false = disabled

public:
    DigitalWallet(string name, double balance, bool status) {
        userName = name;
        walletBalance = balance;
        walletStatus = status;
    }

    friend class WalletManager;
};

class WalletManager {
public:
    void displayDetails(DigitalWallet &w) {
        cout << "\n----- Wallet Details -----" << endl;
        cout << "User Name       : " << w.userName << endl;
        cout << "Wallet Balance  : " << w.walletBalance << endl;
        cout << "Wallet Status   : " << (w.walletStatus ? "Active" : "Disabled") << endl;
        cout << "---------------------------" << endl;
    }

    void addMoney(DigitalWallet &w, double amount) {
        if (!w.walletStatus) {
            cout << "Cannot add money. Wallet is disabled." << endl;
            return;
        }
        w.walletBalance += amount;
        cout << amount << " added to " << w.userName << "'s wallet." << endl;
    }

    void deductMoney(DigitalWallet &w, double amount) {
        if (!w.walletStatus) {
            cout << "Cannot deduct money. Wallet is disabled." << endl;
            return;
        }
        if (w.walletBalance >= amount) {
            w.walletBalance -= amount;
            cout << amount << " deducted from " << w.userName << "'s wallet." << endl;
        } else {
            cout << "Insufficient balance to deduct " << amount << "." << endl;
        }
    }

    void disableWallet(DigitalWallet &w) {
        w.walletStatus = false;
        cout << w.userName << "'s wallet has been disabled." << endl;
    }

    void showStatus(DigitalWallet &w) {
        cout << w.userName << "'s wallet is currently "
             << (w.walletStatus ? "Active" : "Disabled") << "." << endl;
    }
};

int main() {
    string name;
    double balance, amount;

    cout << "Enter user name: ";
    getline(cin, name);
    cout << "Enter initial wallet balance: ";
    cin >> balance;

    DigitalWallet w(name, balance, true);
    WalletManager manager;

    manager.displayDetails(w);

    cout << "\nEnter amount to add: ";
    cin >> amount;
    manager.addMoney(w, amount);
    manager.displayDetails(w);

    cout << "\nEnter amount to deduct: ";
    cin >> amount;
    manager.deductMoney(w, amount);
    manager.displayDetails(w);

    manager.disableWallet(w);
    manager.showStatus(w);

    return 0;
}
