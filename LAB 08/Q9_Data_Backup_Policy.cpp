#include <iostream>
#include <iomanip>
using namespace std;

class BackupPolicy {
public:
    virtual double calculateStorage(double dataSize) {
        return 0;
    }

    virtual ~BackupPolicy() {}
};

class FullBackup : public BackupPolicy {
public:
    double calculateStorage(double dataSize) override {
        return dataSize;
    }
};

class IncrementalBackup : public BackupPolicy {
public:
    double calculateStorage(double dataSize) override {
        return dataSize * 0.25 + 50;
    }
};

int main() {
    FullBackup full;
    IncrementalBackup incremental;
    BackupPolicy* policy;

    double dataSize = 1000;
    cout << fixed << setprecision(2);

    policy = &full;
    cout << "Full Backup Storage: "
         << policy->calculateStorage(dataSize) << " MB" << endl;

    policy = &incremental;
    cout << "Incremental Backup Storage: "
         << policy->calculateStorage(dataSize) << " MB" << endl;

    return 0;
}