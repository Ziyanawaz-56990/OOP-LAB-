#include <iostream>
using namespace std;

class Matrix {
private:
    int value[2][2];

public:
    Matrix() {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                value[i][j] = 0;
    }

    void read() {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                cin >> value[i][j];
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                result.value[i][j] = value[i][j] + other.value[i][j];
        return result;
    }

    void display() const {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j)
                cout << value[i][j] << (j == 0 ? " " : "");
            cout << '\n';
        }
    }
};

int main() {
    Matrix a, b;
    cout << "Enter the 4 elements of first 2x2 matrix row-wise: ";
    a.read();
    cout << "Enter the 4 elements of second 2x2 matrix row-wise: ";
    b.read();

    Matrix sum = a + b;
    cout << "First matrix:\n"; a.display();
    cout << "Second matrix:\n"; b.display();
    cout << "Sum matrix:\n"; sum.display();
    return 0;
}
