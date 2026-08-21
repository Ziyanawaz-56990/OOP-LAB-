#include <iostream>
#include <string>
using namespace std;

class ElectricMeter {
private:
    string meterNumber;
    string consumerName;
    double unitsConsumed;

public:
    ElectricMeter(string mNum, string cName, double units) {
        meterNumber = mNum;
        consumerName = cName;
        unitsConsumed = units;
    }

    friend void checkUsage(ElectricMeter e);
};

void checkUsage(ElectricMeter e) {
    cout << "\n----- Electricity Usage Report -----" << endl;
    cout << "Meter Number    : " << e.meterNumber << endl;
    cout << "Consumer Name   : " << e.consumerName << endl;
    cout << "Units Consumed  : " << e.unitsConsumed << endl;

    if (e.unitsConsumed < 100)
        cout << "Usage Category  : Low Usage" << endl;
    else if (e.unitsConsumed >= 100 && e.unitsConsumed <= 300)
        cout << "Usage Category  : Moderate Usage" << endl;
    else
        cout << "Usage Category  : High Usage" << endl;
    cout << "-------------------------------------" << endl;
}

int main() {
    string meterNumber, consumerName;
    double units;

    cout << "Enter meter number: ";
    getline(cin, meterNumber);
    cout << "Enter consumer name: ";
    getline(cin, consumerName);
    cout << "Enter units consumed: ";
    cin >> units;

    ElectricMeter e(meterNumber, consumerName, units);
    checkUsage(e);

    return 0;
}
