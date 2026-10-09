#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    bool operator!=(const Date& other) const {
        return !(*this == other);
    }

    void display() const {
        cout << day << '/' << month << '/' << year;
    }
};

int main() {
    int d1, m1, y1, d2, m2, y2;
    cout << "Enter first date (day month year): ";
    cin >> d1 >> m1 >> y1;
    cout << "Enter second date (day month year): ";
    cin >> d2 >> m2 >> y2;

    Date a(d1, m1, y1), b(d2, m2, y2);
    cout << "First date: "; a.display(); cout << '\n';
    cout << "Second date: "; b.display(); cout << '\n';
    cout << "Dates equal (==): " << (a == b ? "true" : "false") << '\n';
    cout << "Dates different (!=): " << (a != b ? "true" : "false") << '\n';
    return 0;
}
