#include <iostream>
using namespace std;

class TrafficSignal {
public:
    virtual int getGreenDuration(int vehicleCount) {
        return 0;
    }

    virtual ~TrafficSignal() {}
};

class UrbanSignal : public TrafficSignal {
public:
    int getGreenDuration(int vehicleCount) override {
        int duration = 10 + 2 * vehicleCount;
        return (duration > 60) ? 60 : duration;
    }
};

class HighwaySignal : public TrafficSignal {
public:
    int getGreenDuration(int vehicleCount) override {
        int duration = 15 + 3 * vehicleCount;
        return (duration > 90) ? 90 : duration;
    }
};

int main() {
    UrbanSignal urban;
    HighwaySignal highway;
    TrafficSignal* signal;

    int vehicles = 20;

    signal = &urban;
    cout << "Urban Green Duration: "
         << signal->getGreenDuration(vehicles) << " seconds" << endl;

    signal = &highway;
    cout << "Highway Green Duration: "
         << signal->getGreenDuration(vehicles) << " seconds" << endl;

    return 0;
}