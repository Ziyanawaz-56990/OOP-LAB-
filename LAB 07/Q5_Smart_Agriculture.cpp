#include <iostream>
using namespace std;

class Sensor {
protected:
    int sensorID;

public:
    Sensor(int id) {
        sensorID = id;
    }
};

class Temperature : virtual public Sensor {
protected:
    double temperature;

public:
    Temperature(int id, double temp) : Sensor(id) {
        temperature = temp;
    }
};

class Humidity : virtual public Sensor {
protected:
    double humidity;

public:
    Humidity(int id, double hum) : Sensor(id) {
        humidity = hum;
    }
};

class FarmMonitor : public Temperature, public Humidity {
public:
    FarmMonitor(int id, double temp, double hum)
        : Sensor(id), Temperature(id, temp), Humidity(id, hum) {}

    void displayStatus() {
        cout << "Sensor ID: " << sensorID << endl;
        cout << "Temperature: " << temperature << " C" << endl;
        cout << "Humidity: " << humidity << "%" << endl;

        if (temperature > 35 || humidity > 80)
            cout << "Warning: Farm conditions exceed safe limits." << endl;
        else
            cout << "Farm conditions are within the specified limits." << endl;
    }
};

int main() {
    FarmMonitor farm(501, 37, 75);
    farm.displayStatus();
    return 0;
}