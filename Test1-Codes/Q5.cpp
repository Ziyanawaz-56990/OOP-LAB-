#include <iostream>
using namespace std;
class Trip {
int tripId;
double distance, baseFare;
public:
    Trip(int id, double d, double b) {
        tripId = id;
        distance = d;
        baseFare = b;
    }

    double fare() {
        return baseFare + distance * 12;
    }

    double fare(int waitingTime) {
        return fare() + waitingTime * 2;
    }

    double fare(int waitingTime, int discount) {
        double total = fare(waitingTime);
        return total - total * discount / 100.0;
    }

    friend void compareTrip(Trip &, Trip &);
};
void compareTrip(Trip &a, Trip &b) {
    double fareA = a.fare();
    double fareB = b.fare();

    if (fareA < fareB)
        cout << "Trip " << a.tripId << " is cheaper: " << fareA << "\n";
    else if (fareB < fareA)
        cout << "Trip " << b.tripId << " is cheaper: " << fareB << "\n";
    else
        cout << "Both trips have the same fare\n";
}
int main(){
Trip *a = new Trip(1, 10, 50);
Trip *b = new Trip(2, 7, 60);
cout << "Trip 1 normal fare: " << a->fare() << "\n";
cout << "Trip 1 with waiting: " << a->fare(5) << "\n";
cout << "Trip 1 with waiting and discount: " << a->fare(5, 10) << "\n";
 cout << "Trip 2 normal fare: " << b->fare() << "\n";
cout << "Trip 2 with waiting: " << b->fare(3) << "\n";
cout << "Trip 2 with waiting and discount: " << b->fare(3, 5) << "\n";
 compareTrip(*a, *b);
delete a;
delete b;
return 0;
} Bershet change, Island, capadica ranning several