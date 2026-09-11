#include <iostream>
using namespace std;

class ParkingFloor {
private:
    int floorNumber;
    int numSlots;
    bool *slots; // true = occupied, false = free

public:
    ParkingFloor(int fNum, int slotCount) {
        floorNumber = fNum;
        numSlots = slotCount;
        slots = new bool[numSlots];
        for (int i = 0; i < numSlots; i++)
            slots[i] = false;
    }

    // Reserve a single slot
    void reserve(int slotIndex) {
        if (slotIndex < 0 || slotIndex >= numSlots) {
            cout << "Invalid slot number on floor " << floorNumber << endl;
            return;
        }
        if (slots[slotIndex]) {
            cout << "Slot " << slotIndex << " on floor " << floorNumber << " is already occupied." << endl;
        } else {
            slots[slotIndex] = true;
            cout << "Slot " << slotIndex << " on floor " << floorNumber << " reserved." << endl;
        }
    }

    // Reserve a consecutive group of slots starting at startIndex
    void reserve(int startIndex, int count) {
        if (startIndex < 0 || startIndex + count > numSlots) {
            cout << "Invalid range for reservation on floor " << floorNumber << endl;
            return;
        }
        for (int i = startIndex; i < startIndex + count; i++) {
            if (slots[i]) {
                cout << "Slot " << i << " already occupied. Aborting group reservation." << endl;
                return;
            }
        }
        for (int i = startIndex; i < startIndex + count; i++)
            slots[i] = true;
        cout << count << " slots reserved starting from slot " << startIndex
             << " on floor " << floorNumber << endl;
    }

    void display() {
        cout << "Floor " << floorNumber << " status: ";
        for (int i = 0; i < numSlots; i++)
            cout << (slots[i] ? "[X]" : "[ ]");
        cout << endl;
    }

    ~ParkingFloor() {
        delete[] slots;
    }
};

int main() {
    int numFloors;
    cout << "Enter number of floors: ";
    cin >> numFloors;

    ParkingFloor **floors = new ParkingFloor*[numFloors];

    for (int i = 0; i < numFloors; i++) {
        int slotCount;
        cout << "Enter number of slots for floor " << i + 1 << ": ";
        cin >> slotCount;
        floors[i] = new ParkingFloor(i + 1, slotCount);
    }

    // Demonstration of overloaded reserve()
    floors[0]->reserve(0);          // reserve single slot
    floors[0]->reserve(2, 3);       // reserve 3 consecutive slots starting at index 2

    for (int i = 0; i < numFloors; i++)
        floors[i]->display();

    for (int i = 0; i < numFloors; i++)
        delete floors[i];
    delete[] floors;

    return 0;
}
