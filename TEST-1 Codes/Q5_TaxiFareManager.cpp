#include <iostream>
using namespace std;

class Trip {
private:
    int tripID;
    double distance;
    double baseFare;
    double finalFare;

public:
    Trip(int id, double dist, double base) {
        tripID = id;
        distance = dist;
        baseFare = base;
        finalFare = 0.0;
    }

    // Normal fare
    double fare() {
        finalFare = baseFare + distance * 10; // e.g. Rs.10 per km
        return finalFare;
    }

    // Fare with waiting charge
    double fare(int waitingTime) {
        finalFare = baseFare + distance * 10 + waitingTime * 2; // Rs.2 per min waiting
        return finalFare;
    }

    // Fare with waiting charge and discount
    double fare(int waitingTime, int discount) {
        double total = baseFare + distance * 10 + waitingTime * 2;
        finalFare = total - (total * discount / 100.0);
        return finalFare;
    }

    void display() {
        cout << "Trip " << tripID << " | Distance: " << distance
             << " km | Final Fare: " << finalFare << endl;
    }

    // friend function compares fares without a public data member being used
    friend void compareFares(Trip &t1, Trip &t2);
};

void compareFares(Trip &t1, Trip &t2) {
    cout << "\nComparing fares of Trip " << t1.tripID << " and Trip " << t2.tripID << ":\n";
    if (t1.finalFare < t2.finalFare)
        cout << "Trip " << t1.tripID << " is cheaper (Fare: " << t1.finalFare << ")" << endl;
    else if (t2.finalFare < t1.finalFare)
        cout << "Trip " << t2.tripID << " is cheaper (Fare: " << t2.finalFare << ")" << endl;
    else
        cout << "Both trips cost the same: " << t1.finalFare << endl;
}

int main() {
    int id1, id2;
    double dist1, dist2, base1, base2;
    int waitTime1, waitTime2, discount2;

    cout << "Enter Trip 1 ID, distance, base fare: ";
    cin >> id1 >> dist1 >> base1;
    cout << "Enter Trip 2 ID, distance, base fare: ";
    cin >> id2 >> dist2 >> base2;

    Trip *t1 = new Trip(id1, dist1, base1);
    Trip *t2 = new Trip(id2, dist2, base2);

    cout << "Enter waiting time for Trip 1: ";
    cin >> waitTime1;
    cout << "Enter waiting time and discount for Trip 2: ";
    cin >> waitTime2 >> discount2;

    t1->fare(waitTime1);              // fare with waiting charge only
    t2->fare(waitTime2, discount2);   // fare with waiting charge + discount

    t1->display();
    t2->display();

    compareFares(*t1, *t2);

    delete t1;
    delete t2;

    return 0;
}
