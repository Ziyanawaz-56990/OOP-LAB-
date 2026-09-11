#include <iostream>
using namespace std;

class Borrower {
private:
    int borrowerID;
    int overdueDays;
    double fineAmount;

public:
    Borrower(int id, int days) {
        borrowerID = id;
        overdueDays = days;
        fineAmount = 0.0;
    }

    // Fine using only overdue days (flat rate)
    void calculateFine() {
        double ratePerDay = 2.0;
        fineAmount = overdueDays * ratePerDay;
    }

    // Fine using overdue days and a special rate
    void calculateFine(double specialRate) {
        fineAmount = overdueDays * specialRate;
    }

    void display() {
        cout << "Borrower ID: " << borrowerID
             << " | Overdue Days: " << overdueDays
             << " | Fine: " << fineAmount << endl;
    }

    // friend function needs access to private fineAmount
    friend void compareFines(Borrower *b1, Borrower *b2);
};

void compareFines(Borrower *b1, Borrower *b2) {
    cout << "\nComparing fines of Borrower " << b1->borrowerID
         << " and Borrower " << b2->borrowerID << ":\n";
    if (b1->fineAmount > b2->fineAmount)
        cout << "Borrower " << b1->borrowerID << " has the higher fine of " << b1->fineAmount << endl;
    else if (b2->fineAmount > b1->fineAmount)
        cout << "Borrower " << b2->borrowerID << " has the higher fine of " << b2->fineAmount << endl;
    else
        cout << "Both borrowers have the same fine of " << b1->fineAmount << endl;
}

int main() {
    int id1, days1, id2, days2;
    double specialRate;

    cout << "Enter ID and overdue days for Borrower 1: ";
    cin >> id1 >> days1;
    cout << "Enter ID and overdue days for Borrower 2: ";
    cin >> id2 >> days2;
    cout << "Enter special rate for Borrower 2's calculation: ";
    cin >> specialRate;

    Borrower *b1 = new Borrower(id1, days1);
    Borrower *b2 = new Borrower(id2, days2);

    b1->calculateFine();                 // uses overdue days only
    b2->calculateFine(specialRate);      // uses overdue days + special rate

    b1->display();
    b2->display();

    compareFines(b1, b2);

    delete b1;
    delete b2;

    return 0;
}
