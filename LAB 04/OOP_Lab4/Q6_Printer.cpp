#include <iostream>
#include <string>
using namespace std;

class PrinterManager; // forward declaration

class Printer {
private:
    string printerName;
    int pagesPrinted;
    int inkLevel;       // percentage
    bool powerStatus;   // true = ON, false = OFF

public:
    Printer(string name, int pages, int ink, bool power) {
        printerName = name;
        pagesPrinted = pages;
        inkLevel = ink;
        powerStatus = power;
    }

    friend class PrinterManager;
};

class PrinterManager {
public:
    void displayInfo(Printer &p) {
        cout << "\n----- Printer Information -----" << endl;
        cout << "Printer Name    : " << p.printerName << endl;
        cout << "Pages Printed   : " << p.pagesPrinted << endl;
        cout << "Ink Level       : " << p.inkLevel << "%" << endl;
        cout << "Power Status    : " << (p.powerStatus ? "ON" : "OFF") << endl;
        cout << "--------------------------------" << endl;
    }

    void turnOn(Printer &p) {
        p.powerStatus = true;
        cout << p.printerName << " turned ON." << endl;
    }

    void turnOff(Printer &p) {
        p.powerStatus = false;
        cout << p.printerName << " turned OFF." << endl;
    }

    void checkInkLevel(Printer &p) {
        cout << "Ink Level of " << p.printerName << ": " << p.inkLevel << "%" << endl;
        if (p.inkLevel < 20)
            cout << "Warning: Ink level low!" << endl;
    }

    void resetPageCount(Printer &p) {
        p.pagesPrinted = 0;
        cout << "Page count reset for " << p.printerName << "." << endl;
    }
};

int main() {
    string name;
    int pages, ink;

    cout << "Enter printer name: ";
    getline(cin, name);
    cout << "Enter pages printed: ";
    cin >> pages;
    cout << "Enter ink level (%): ";
    cin >> ink;

    Printer p(name, pages, ink, false);
    PrinterManager manager;

    manager.displayInfo(p);
    manager.turnOn(p);
    manager.checkInkLevel(p);
    manager.resetPageCount(p);
    manager.displayInfo(p);
    manager.turnOff(p);
    manager.displayInfo(p);

    return 0;
}
