#include <iostream>
using namespace std;

class Candidate {
protected:
    int candidateID;
    double attendance;

public:
    Candidate(int id, double att) {
        candidateID = id;
        attendance = att;
    }
};

class RegularCandidate : public Candidate {
public:
    RegularCandidate(int id, double att) : Candidate(id, att) {}

    void checkEligibility() {
        cout << "Regular Candidate ID: " << candidateID << endl;
        if (attendance >= 75)
            cout << "Eligible for examination." << endl;
        else
            cout << "Not eligible for examination." << endl;
    }
};

class ReappearCandidate : public Candidate {
public:
    ReappearCandidate(int id, double att) : Candidate(id, att) {}

    void checkEligibility() {
        cout << "Reappear Candidate ID: " << candidateID << endl;
        if (attendance >= 60)
            cout << "Eligible for examination." << endl;
        else
            cout << "Not eligible for examination." << endl;
    }
};

int main() {
    RegularCandidate regular(101, 78);
    ReappearCandidate reappear(102, 65);

    regular.checkEligibility();
    cout << endl;
    reappear.checkEligibility();
    return 0;
}