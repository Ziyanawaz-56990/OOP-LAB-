#include <iostream>
using namespace std;
class Borrower {
int id, days;
double fine;
public:
    Borrower(int i, int d) {
        id = i;
        days = d;
        fine = 0;
    }
void calculateFine() {
        fine = days * 2.0;
    }
void calculateFine(double specialRate) {
        fine = days * specialRate;
    }
void show() {
        cout << "Borrower " << id << " fine = " << fine << "\n";
    }
friend void compareFine(Borrower &, Borrower &);
};
void compareFine(Borrower &a, Borrower &b) {
    if (a.fine > b.fine)
        cout << "Borrower " << a.id << " has the higher fine\n";
    else if (b.fine > a.fine)
        cout << "Borrower " << b.id << " has the higher fine\n";
    else
        cout << "Both borrowers have the same fine\n";
}
int main() {
    Borrower *a = new Borrower(101, 8);
    Borrower *b = new Borrower(102, 5);
  a->calculateFine();
    b->calculateFine(3.0);
 a->show();
 b->show();
  compareFine(*a, *b);
delete a;
 delete b;
return 0;
}