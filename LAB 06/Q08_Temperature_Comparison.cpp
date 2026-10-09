#include <iostream>
using namespace std;

class Temperature {
private:
    double celsius;

public:
    explicit Temperature(double c) : celsius(c) {}

    bool operator>(const Temperature& other) const {
        return celsius > other.celsius;
    }

    bool operator<(const Temperature& other) const {
        return celsius < other.celsius;
    }

    Temperature operator-() const {
        return Temperature(-celsius);
    }

    void display() const { cout << celsius << " C"; }
};

int main() {
    double t1, t2;
    cout << "Enter first temperature in Celsius: ";
    cin >> t1;
    cout << "Enter second temperature in Celsius: ";
    cin >> t2;

    Temperature a(t1), b(t2), negated = -a;
    cout << "First temperature: "; a.display(); cout << '\n';
    cout << "Second temperature: "; b.display(); cout << '\n';
    cout << "First > second: " << (a > b ? "true" : "false") << '\n';
    cout << "First < second: " << (a < b ? "true" : "false") << '\n';
    cout << "Negation of first temperature: "; negated.display(); cout << '\n';
    return 0;
}
