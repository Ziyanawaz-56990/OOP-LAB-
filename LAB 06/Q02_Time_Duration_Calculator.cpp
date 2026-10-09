#include <iostream>
using namespace std;

class Duration {
private:
    int hours, minutes;

public:
    Duration(int h = 0, int m = 0) : hours(h), minutes(m) {
        hours += minutes / 60;
        minutes %= 60;
    }

    Duration operator+(const Duration& other) const {
        return Duration(hours + other.hours, minutes + other.minutes);
    }

    void display() const {
        cout << hours << " hour(s) " << minutes << " minute(s)";
    }
};

int main() {
    int h1, m1, h2, m2;
    cout << "Enter first duration (hours minutes): ";
    cin >> h1 >> m1;
    cout << "Enter second duration (hours minutes): ";
    cin >> h2 >> m2;

    Duration a(h1, m1), b(h2, m2), total = a + b;
    cout << "First duration: "; a.display(); cout << '\n';
    cout << "Second duration: "; b.display(); cout << '\n';
    cout << "Total duration: "; total.display(); cout << '\n';
    return 0;
}
