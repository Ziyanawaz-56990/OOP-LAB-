#include <iostream>
using namespace std;

class LibraryAccess {
protected:
    int borrowedBooks;

public:
    LibraryAccess(int books) {
        borrowedBooks = books;
    }
};

class LaboratoryAccess {
protected:
    int pendingSubmissions;

public:
    LaboratoryAccess(int pending) {
        pendingSubmissions = pending;
    }
};

class StudentAccess : public LibraryAccess, public LaboratoryAccess {
public:
    StudentAccess(int books, int pending)
        : LibraryAccess(books), LaboratoryAccess(pending) {}

    void displayAccessStatus() {
        cout << "Books currently borrowed: " << borrowedBooks << endl;
        cout << "Pending lab submissions: " << pendingSubmissions << endl;

        if (borrowedBooks <= 5 && pendingSubmissions == 0)
            cout << "Full resource access granted." << endl;
        else
            cout << "Full resource access not granted." << endl;
    }
};

int main() {
    StudentAccess student(3, 0);
    student.displayAccessStatus();
    return 0;
}