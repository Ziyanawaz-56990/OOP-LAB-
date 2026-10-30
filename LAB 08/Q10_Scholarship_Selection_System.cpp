#include <iostream>
using namespace std;

class Scholarship {
public:
    virtual double calculateAward(double marks, double familyIncome) {
        return 0;
    }

    virtual ~Scholarship() {}
};

class MeritScholarship : public Scholarship {
public:
    double calculateAward(double marks, double familyIncome) override {
        if (marks >= 90)
            return 20000;
        else if (marks >= 80)
            return 10000;
        else
            return 0;
    }
};

class NeedBasedScholarship : public Scholarship {
public:
    double calculateAward(double marks, double familyIncome) override {
        if (familyIncome < 200000 && marks >= 70)
            return 25000;
        return 0;
    }
};

int main() {
    MeritScholarship merit;
    NeedBasedScholarship need;
    Scholarship* scholarship;

    double marks = 85;
    double familyIncome = 180000;

    scholarship = &merit;
    cout << "Merit Scholarship Award: Rs. "
         << scholarship->calculateAward(marks, familyIncome) << endl;

    scholarship = &need;
    cout << "Need-Based Scholarship Award: Rs. "
         << scholarship->calculateAward(marks, familyIncome) << endl;

    return 0;
}