#include <iostream>
using namespace std;

class SensorGrid {
private:
    int n;
    double *readings;

public:
    SensorGrid(int count) {
        n = count;
        readings = new double[n];
    }

    void enterReadings() {
        cout << "Enter " << n << " temperature readings:\n";
        for (int i = 0; i < n; i++)
            cin >> readings[i];
    }

    void displayReadings() {
        cout << "Readings: ";
        for (int i = 0; i < n; i++)
            cout << readings[i] << " ";
        cout << endl;
    }

    void replaceReading(int pos, double newValue) {
        if (pos < 0 || pos >= n) {
            cout << "Invalid position." << endl;
            return;
        }
        readings[pos] = newValue;
    }

    double average() const {
        double sum = 0;
        for (int i = 0; i < n; i++)
            sum += readings[i];
        return (n == 0) ? 0 : sum / n;
    }

    // friend function comparing two grids that may have different sizes
    friend void compareAverages(const SensorGrid &g1, const SensorGrid &g2);

    ~SensorGrid() {
        delete[] readings;
    }
};

void compareAverages(const SensorGrid &g1, const SensorGrid &g2) {
    double avg1 = g1.average();
    double avg2 = g2.average();

    cout << "\nGrid 1 average: " << avg1 << endl;
    cout << "Grid 2 average: " << avg2 << endl;

    if (avg1 > avg2)
        cout << "Grid 1 has the greater average temperature." << endl;
    else if (avg2 > avg1)
        cout << "Grid 2 has the greater average temperature." << endl;
    else
        cout << "Both grids have the same average temperature." << endl;
}

int main() {
    int n1, n2;
    cout << "Enter number of sensors in Grid 1: ";
    cin >> n1;
    cout << "Enter number of sensors in Grid 2: ";
    cin >> n2;

    SensorGrid grid1(n1);
    SensorGrid grid2(n2);

    grid1.enterReadings();
    grid2.enterReadings();

    grid1.displayReadings();
    grid2.displayReadings();

    // demonstrate replacing a reading
    grid1.replaceReading(0, 99.9);
    cout << "\nAfter replacing position 0 in Grid 1:\n";
    grid1.displayReadings();

    compareAverages(grid1, grid2);

    return 0;
}
