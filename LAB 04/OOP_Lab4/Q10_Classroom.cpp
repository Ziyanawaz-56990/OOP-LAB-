#include <iostream>
#include <string>
using namespace std;

class AttendanceManager; // forward declaration

class Classroom {
private:
    string className;
    int totalStudents;
    int presentStudents;
    bool attendanceStatus; // true = completed, false = not completed

public:
    Classroom(string name, int total, int present, bool status) {
        className = name;
        totalStudents = total;
        presentStudents = present;
        attendanceStatus = status;
    }

    friend class AttendanceManager;
};

class AttendanceManager {
public:
    void displayInfo(Classroom &c) {
        cout << "\n----- Classroom Information -----" << endl;
        cout << "Class Name        : " << c.className << endl;
        cout << "Total Students    : " << c.totalStudents << endl;
        cout << "Present Students  : " << c.presentStudents << endl;
        cout << "Attendance Status : " << (c.attendanceStatus ? "Completed" : "Not Completed") << endl;
        cout << "----------------------------------" << endl;
    }

    void updatePresentStudents(Classroom &c, int present) {
        c.presentStudents = present;
        cout << "Present students updated to " << present << " for " << c.className << "." << endl;
    }

    void markAttendanceCompleted(Classroom &c) {
        c.attendanceStatus = true;
        cout << "Attendance marked as completed for " << c.className << "." << endl;
    }

    void showAttendanceStatus(Classroom &c) {
        cout << "Attendance for " << c.className << " is "
             << (c.attendanceStatus ? "Completed" : "Not Completed") << "." << endl;
    }

    void calculateAbsentees(Classroom &c) {
        int absent = c.totalStudents - c.presentStudents;
        cout << "Absent Students in " << c.className << " : " << absent << endl;
    }
};

int main() {
    string name;
    int total, present;

    cout << "Enter class name: ";
    getline(cin, name);
    cout << "Enter total number of students: ";
    cin >> total;
    cout << "Enter number of present students: ";
    cin >> present;

    Classroom c(name, total, present, false);
    AttendanceManager manager;

    manager.displayInfo(c);
    manager.updatePresentStudents(c, present);
    manager.calculateAbsentees(c);
    manager.markAttendanceCompleted(c);
    manager.showAttendanceStatus(c);
    manager.displayInfo(c);

    return 0;
}
