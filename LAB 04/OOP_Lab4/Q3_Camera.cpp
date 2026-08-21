#include <iostream>
#include <string>
using namespace std;

class Camera {
private:
    string brand;
    string model;
    double megapixels;
    double storageCapacity; // in GB

public:
    Camera(string b, string m, double mp, double storage) {
        brand = b;
        model = m;
        megapixels = mp;
        storageCapacity = storage;
    }

    friend void compareCamera(Camera c1, Camera c2);
};

void compareCamera(Camera c1, Camera c2) {
    Camera better = c1;

    if (c1.megapixels > c2.megapixels) {
        better = c1;
    } else if (c2.megapixels > c1.megapixels) {
        better = c2;
    } else {
        // same megapixels, compare storage
        better = (c1.storageCapacity >= c2.storageCapacity) ? c1 : c2;
    }

    cout << "\n----- Better Camera -----" << endl;
    cout << "Brand           : " << better.brand << endl;
    cout << "Model           : " << better.model << endl;
    cout << "Megapixels      : " << better.megapixels << " MP" << endl;
    cout << "Storage         : " << better.storageCapacity << " GB" << endl;
    cout << "--------------------------" << endl;
}

int main() {
    string brand1, model1, brand2, model2;
    double mp1, mp2, storage1, storage2;

    cout << "Enter Camera 1 Brand: ";
    getline(cin, brand1);
    cout << "Enter Camera 1 Model: ";
    getline(cin, model1);
    cout << "Enter Camera 1 Megapixels: ";
    cin >> mp1;
    cout << "Enter Camera 1 Storage Capacity (GB): ";
    cin >> storage1;
    cin.ignore();

    cout << "\nEnter Camera 2 Brand: ";
    getline(cin, brand2);
    cout << "Enter Camera 2 Model: ";
    getline(cin, model2);
    cout << "Enter Camera 2 Megapixels: ";
    cin >> mp2;
    cout << "Enter Camera 2 Storage Capacity (GB): ";
    cin >> storage2;

    Camera cam1(brand1, model1, mp1, storage1);
    Camera cam2(brand2, model2, mp2, storage2);

    compareCamera(cam1, cam2);

    return 0;
}
