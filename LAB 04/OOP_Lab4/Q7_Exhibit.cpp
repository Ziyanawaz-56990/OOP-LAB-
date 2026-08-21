#include <iostream>
#include <string>
using namespace std;

class MuseumManager; // forward declaration

class Exhibit {
private:
    string exhibitName;
    int exhibitID;
    int visitorCount;
    bool displayStatus; // true = open, false = closed

public:
    Exhibit(string name, int id, int visitors, bool status) {
        exhibitName = name;
        exhibitID = id;
        visitorCount = visitors;
        displayStatus = status;
    }

    friend class MuseumManager;
};

class MuseumManager {
public:
    void displayInfo(Exhibit &e) {
        cout << "\n----- Exhibit Information -----" << endl;
        cout << "Exhibit Name    : " << e.exhibitName << endl;
        cout << "Exhibit ID      : " << e.exhibitID << endl;
        cout << "Visitor Count   : " << e.visitorCount << endl;
        cout << "Display Status  : " << (e.displayStatus ? "Open" : "Closed") << endl;
        cout << "--------------------------------" << endl;
    }

    void addVisitors(Exhibit &e, int count) {
        e.visitorCount += count;
        cout << count << " visitor(s) added to " << e.exhibitName << "." << endl;
    }

    void resetVisitorCount(Exhibit &e) {
        e.visitorCount = 0;
        cout << "Visitor count reset for " << e.exhibitName << "." << endl;
    }

    void openExhibit(Exhibit &e) {
        e.displayStatus = true;
        cout << e.exhibitName << " is now Open." << endl;
    }

    void closeExhibit(Exhibit &e) {
        e.displayStatus = false;
        cout << e.exhibitName << " is now Closed." << endl;
    }

    void showOpenStatus(Exhibit &e) {
        cout << e.exhibitName << " is currently "
             << (e.displayStatus ? "Open" : "Closed") << "." << endl;
    }
};

int main() {
    string name;
    int id, visitors;

    cout << "Enter exhibit name: ";
    getline(cin, name);
    cout << "Enter exhibit ID: ";
    cin >> id;
    cout << "Enter current visitor count: ";
    cin >> visitors;

    Exhibit e(name, id, visitors, false);
    MuseumManager manager;

    manager.displayInfo(e);
    manager.openExhibit(e);
    manager.addVisitors(e, 25);
    manager.showOpenStatus(e);
    manager.displayInfo(e);
    manager.resetVisitorCount(e);
    manager.closeExhibit(e);
    manager.displayInfo(e);

    return 0;
}
