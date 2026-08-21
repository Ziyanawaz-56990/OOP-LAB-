#include <iostream>
#include <string>
using namespace std;

class Weather {
private:
    string cityName;
    double temperature;
    string weatherCondition;

public:
    Weather(string city, double temp, string condition) {
        cityName = city;
        temperature = temp;
        weatherCondition = condition;
    }

    friend void generateReport(Weather w);
};

void generateReport(Weather w) {
    cout << "\n----- Weather Report -----" << endl;
    cout << "City            : " << w.cityName << endl;
    cout << "Temperature     : " << w.temperature << " C" << endl;
    cout << "Condition       : " << w.weatherCondition << endl;

    if (w.temperature > 35)
        cout << "Category        : Very Hot" << endl;
    else if (w.temperature >= 20 && w.temperature <= 35)
        cout << "Category        : Pleasant" << endl;
    else
        cout << "Category        : Cool" << endl;
    cout << "---------------------------" << endl;
}

int main() {
    string city, condition;
    double temp;

    cout << "Enter city name: ";
    getline(cin, city);
    cout << "Enter temperature (C): ";
    cin >> temp;
    cin.ignore();
    cout << "Enter weather condition: ";
    getline(cin, condition);

    Weather w(city, temp, condition);
    generateReport(w);

    return 0;
}
