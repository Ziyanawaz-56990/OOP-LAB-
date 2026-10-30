#include <iostream>
#include <iomanip>
using namespace std;

class ElectricityPlan {
public:
    virtual double calculateBill(double units) {
        return 0;
    }

    virtual ~ElectricityPlan() {}
};

class ResidentialPlan : public ElectricityPlan {
public:
    double calculateBill(double units) override {
        if (units <= 100)
            return units * 4;
        return 100 * 4 + (units - 100) * 6;
    }
};

class CommercialPlan : public ElectricityPlan {
public:
    double calculateBill(double units) override {
        return units * 7;
    }
};

int main() {
    ResidentialPlan residential;
    CommercialPlan commercial;
    ElectricityPlan* plan;

    double units = 150;
    cout << fixed << setprecision(2);

    plan = &residential;
    cout << "Residential Bill: Rs. " << plan->calculateBill(units) << endl;

    plan = &commercial;
    cout << "Commercial Bill: Rs. " << plan->calculateBill(units) << endl;

    return 0;
}