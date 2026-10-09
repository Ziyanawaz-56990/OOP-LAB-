#include <iostream>
#include <numeric>
#include <cstdlib>
using namespace std;

class Fraction {
private:
    long long numerator, denominator;

    void simplify() {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        long long g = gcd(llabs(numerator), llabs(denominator));
        if (g != 0) {
            numerator /= g;
            denominator /= g;
        }
    }

public:
    Fraction(long long n = 0, long long d = 1)
        : numerator(n), denominator(d) {
        simplify();
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator +
                        other.numerator * denominator,
                        denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator -
                        other.numerator * denominator,
                        denominator * other.denominator);
    }

    void display() const {
        cout << numerator << "/" << denominator;
    }
};

int main() {
    try {
        long long n1, d1, n2, d2;
        cout << "Enter first fraction (numerator denominator): ";
        cin >> n1 >> d1;
        cout << "Enter second fraction (numerator denominator): ";
        cin >> n2 >> d2;

        Fraction a(n1, d1), b(n2, d2);
        cout << "First fraction: "; a.display(); cout << '\n';
        cout << "Second fraction: "; b.display(); cout << '\n';
        cout << "Sum: "; (a + b).display(); cout << '\n';
        cout << "Difference (first - second): "; (a - b).display(); cout << '\n';
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
