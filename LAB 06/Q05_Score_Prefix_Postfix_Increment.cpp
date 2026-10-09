#include <iostream>
using namespace std;

class Score {
private:
    int value;

public:
    explicit Score(int v = 0) : value(v) {}

    Score& operator++() {          // Prefix: increment, then return updated object
        ++value;
        return *this;
    }

    Score operator++(int) {        // Postfix: save old value, then increment
        Score old = *this;
        value++;
        return old;
    }

    void display() const { cout << value; }
};

int main() {
    int initial;
    cout << "Enter initial score: ";
    cin >> initial;

    Score prefix(initial), postfix(initial);
    Score prefixResult = ++prefix;
    Score postfixResult = postfix++;

    cout << "Initial score for each demonstration: " << initial << '\n';
    cout << "Result of prefix ++obj: "; prefixResult.display(); cout << '\n';
    cout << "Object after prefix: "; prefix.display(); cout << '\n';
    cout << "Result of postfix obj++: "; postfixResult.display(); cout << '\n';
    cout << "Object after postfix: "; postfix.display(); cout << '\n';
    return 0;
}
