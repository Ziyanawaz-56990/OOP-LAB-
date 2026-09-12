#include <iostream>
using namespace std;
class ParkingFloor {
 int floorNo, slots;
bool *occupied;
public:
    ParkingFloor(int f, int s) {
        floorNo = f;
        slots = s;
        occupied = new bool[slots];
        for (int i = 0; i < slots; i++)
            occupied[i] = false;
    }
void reserve(int pos) {
        if (pos < 1 || pos > slots) {
            cout << "Invalid slot\n";
            return;
        }
        if (occupied[pos - 1])
            cout << "Slot already reserved\n";
        else {
            occupied[pos - 1] = true;
            cout << "Slot " << pos << " reserved\n";
        }
      } void reserve(int start, int count) {
        if (start < 1 || start + count - 1 > slots) {
            cout << "Invalid range\n";
            return;
        }
         for (int i = start - 1; i < start - 1 + count; i++) {
            if (occupied[i]) {
                cout << "Some slots are already reserved\n";
      return;
            }}
for (int i = start - 1; i < start - 1 + count; i++)
            occupied[i] = true;

        cout << count << " slots reserved from " << start << "\n";
    }
    void show() {
        cout << "Floor " << floorNo << ": ";
        for (int i = 0; i < slots; i++)
            cout << (occupied[i] ? "X " : "O ");
        cout << "\n";
    } ~ParkingFloor() {
        delete[] occupied;
    }
};
int main() {
    int n;
    cout << "Enter number of floors: ";
    cin >> n;
 ParkingFloor **floors = new ParkingFloor*[n];
for (int i = 0; i < n; i++) {
        int slots;
        cout << "Enter slots for floor " << i + 1 << ": ";
        cin >> slots;
        floors[i] = new ParkingFloor(i + 1, slots);
    }
    floors[0]->reserve(2);
    floors[0]->reserve(4, 2);
    for (int i = 0; i < n; i++)
        floors[i]->show();
for (int i = 0; i < n; i++)
        delete floors[i];
    delete[] floors;
return 0;
}