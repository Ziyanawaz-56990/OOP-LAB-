#include <iostream>
using namespace std;
class SensorGrid {
int n;
double *temp;
public:
    SensorGrid(int size) {
        n = size;
        temp = new double[n];
    }
void enter() {
 for (int i = 0; i < n; i++) {
      cout << "Temperature " << i + 1 << ": ";
     cin >> temp[i];
        }
    }
 void display() {
        cout << "Readings: ";
        for (int i = 0; i < n; i++)
            cout << temp[i] << " ";
        cout << "\n";
    }
 void replaceReading(int pos, double value) {
        if (pos >= 1 && pos <= n)
            temp[pos - 1] = value;
        else
            cout << "Invalid position\n";
    }
 double average() const {
        double sum = 0;
        for (int i = 0; i < n; i++)
            sum += temp[i];
        return sum / n;
    }
friend void compareAverage(const SensorGrid &, const SensorGrid &);
~SensorGrid() {
        delete[] temp;
    }
};
void compareAverage(const SensorGrid &a, const SensorGrid &b) {
    double x = a.average();
    double y = b.average();
 if (x > y)
        cout << "First grid has the greater average: " << x << "\n";
 else if (y > x)
        cout << "Second grid has the greater average: " << y << "\n";
else cout << "Both grids have the same average\n";
}
int main() {
    int n1, n2;
    cout << "Enter number of readings in first grid: ";
    cin >> n1;
    SensorGrid *a = new SensorGrid(n1);
    a->enter();

    cout << "Enter number of readings in second grid: ";
    cin >> n2;
    SensorGrid *b = new SensorGrid(n2);
    b->enter();

    cout << "\nFirst grid\n";
    a->display();

    cout << "Second grid\n";
    b->display();

    a->replaceReading(1, 25.5);

    cout << "After replacement:\n";
    a->display();

    compareAverage(*a, *b);

    delete a;
    delete b;
    return 0;
}