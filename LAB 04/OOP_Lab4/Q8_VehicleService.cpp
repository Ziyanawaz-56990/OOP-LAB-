#include <iostream>
#include <string>
using namespace std;

class ServiceManager; // forward declaration

class VehicleService {
private:
    string vehicleNumber;
    string ownerName;
    bool serviceDue;          // true = service due
    double lastServiceKm;

public:
    VehicleService(string vNum, string owner, bool due, double lastKm) {
        vehicleNumber = vNum;
        ownerName = owner;
        serviceDue = due;
        lastServiceKm = lastKm;
    }

    friend class ServiceManager;
};

class ServiceManager {
private:
    const double SERVICE_INTERVAL_KM = 5000.0;

public:
    void displayInfo(VehicleService &v) {
        cout << "\n----- Vehicle Service Information -----" << endl;
        cout << "Vehicle Number    : " << v.vehicleNumber << endl;
        cout << "Owner Name        : " << v.ownerName << endl;
        cout << "Service Due       : " << (v.serviceDue ? "Yes" : "No") << endl;
        cout << "Last Service (km) : " << v.lastServiceKm << endl;
        cout << "-----------------------------------------" << endl;
    }

    void markServiceCompleted(VehicleService &v, double currentKm) {
        v.serviceDue = false;
        v.lastServiceKm = currentKm;
        cout << "Service marked as completed for " << v.vehicleNumber << "." << endl;
    }

    void updateLastServiceKm(VehicleService &v, double km) {
        v.lastServiceKm = km;
        cout << "Last service kilometres updated to " << km << " for " << v.vehicleNumber << "." << endl;
    }

    void checkServiceRequired(VehicleService &v, double currentKm) {
        double kmSinceService = currentKm - v.lastServiceKm;
        if (kmSinceService >= SERVICE_INTERVAL_KM) {
            v.serviceDue = true;
            cout << v.vehicleNumber << " requires servicing (" << kmSinceService
                 << " km since last service)." << endl;
        } else {
            v.serviceDue = false;
            cout << v.vehicleNumber << " does not require servicing yet ("
                 << kmSinceService << " km since last service)." << endl;
        }
    }
};

int main() {
    string vNum, owner;
    double lastKm, currentKm;

    cout << "Enter vehicle number: ";
    getline(cin, vNum);
    cout << "Enter owner name: ";
    getline(cin, owner);
    cout << "Enter last service kilometres: ";
    cin >> lastKm;

    VehicleService v(vNum, owner, false, lastKm);
    ServiceManager manager;

    manager.displayInfo(v);

    cout << "\nEnter current kilometre reading: ";
    cin >> currentKm;

    manager.checkServiceRequired(v, currentKm);
    manager.displayInfo(v);

    manager.markServiceCompleted(v, currentKm);
    manager.displayInfo(v);

    return 0;
}
