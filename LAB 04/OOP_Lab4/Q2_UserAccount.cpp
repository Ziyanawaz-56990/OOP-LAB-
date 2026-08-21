#include <iostream>
#include <string>
using namespace std;

class UserAccount {
private:
    string username;
    int loginAttempts;
    string accountStatus;

public:
    UserAccount(string uname, int attempts) {
        username = uname;
        loginAttempts = attempts;
        accountStatus = "";
    }

    friend void checkAccount(UserAccount u);
};

void checkAccount(UserAccount u) {
    cout << "\n----- Account Check -----" << endl;
    cout << "Username        : " << u.username << endl;
    cout << "Login Attempts  : " << u.loginAttempts << endl;

    if (u.loginAttempts >= 3)
        cout << "Account Status  : Account Locked" << endl;
    else
        cout << "Account Status  : Account Active" << endl;
    cout << "--------------------------" << endl;
}

int main() {
    string uname;
    int attempts;

    cout << "Enter username: ";
    getline(cin, uname);
    cout << "Enter number of unsuccessful login attempts: ";
    cin >> attempts;

    UserAccount u(uname, attempts);
    checkAccount(u);

    return 0;
}
