#include <iostream>
#include <string>
using namespace std;

class EventParticipant {
private:
    string participantName;
    int age;
    string registrationStatus; // "Active" or "Inactive"

public:
    EventParticipant(string name, int a, string status) {
        participantName = name;
        age = a;
        registrationStatus = status;
    }

    friend void verifyParticipant(EventParticipant p);
};

void verifyParticipant(EventParticipant p) {
    cout << "\n----- Participant Verification -----" << endl;
    cout << "Name              : " << p.participantName << endl;
    cout << "Age               : " << p.age << endl;
    cout << "Registration      : " << p.registrationStatus << endl;

    bool isAdult = (p.age >= 18);
    bool isActive = (p.registrationStatus == "Active" || p.registrationStatus == "active");

    if (isAdult && isActive)
        cout << "Eligibility       : Eligible" << endl;
    else
        cout << "Eligibility       : Not Eligible" << endl;
    cout << "-------------------------------------" << endl;
}

int main() {
    string name, status;
    int age;

    cout << "Enter participant name: ";
    getline(cin, name);
    cout << "Enter age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter registration status (Active/Inactive): ";
    getline(cin, status);

    EventParticipant p(name, age, status);
    verifyParticipant(p);

    return 0;
}
