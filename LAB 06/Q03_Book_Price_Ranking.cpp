#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    double price;

public:
    Book(string t, double p) : title(t), price(p) {}

    bool operator<(const Book& other) const {
        if (price != other.price) return price < other.price;
        return title < other.title;
    }

    void display() const {
        cout << '"' << title << "\" - Rs. " << price;
    }
};

int main() {
    string t1, t2;
    double p1, p2;
    cout << "Enter first book title (one line): ";
    getline(cin, t1);
    cout << "Enter first book price: ";
    cin >> p1;
    cin.ignore(10000, '\\n');
    cout << "Enter second book title (one line): ";
    getline(cin, t2);
    cout << "Enter second book price: ";
    cin >> p2;

    Book a(t1, p1), b(t2, p2);
    cout << "First book: "; a.display(); cout << '\n';
    cout << "Second book: "; b.display(); cout << '\n';
    cout << "First book < second book: " << (a < b ? "true" : "false") << '\n';
    cout << "Second book < first book: " << (b < a ? "true" : "false") << '\n';
    return 0;
}
