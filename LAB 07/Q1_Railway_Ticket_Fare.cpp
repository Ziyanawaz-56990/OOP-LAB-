#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Ticket {
protected:
    string passengerName;
    double distance;

public:
    Ticket(string name, double dist) {
        passengerName = name;
        distance = dist;
    }
};

class RailwayTicket : public Ticket {
private:
    double farePerKm;

public:
    RailwayTicket(string name, double dist, double rate)
        : Ticket(name, dist) {
        farePerKm = rate;
    }

    void displayFare() {
        double fare = distance * farePerKm;

        if (distance > 300) {
            fare = fare - (fare * 0.10);
        }

        cout << "Passenger Name: " << passengerName << endl;
        cout << "Distance: " << distance << " km" << endl;
        cout << fixed << setprecision(2);
        cout << "Final Ticket Fare: Rs. " << fare << endl;
    }
};

int main() {
    RailwayTicket ticket("Aarav", 350, 2.5);
    ticket.displayFare();
    return 0;
}