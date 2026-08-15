#include <iostream>
#include <string>
using namespace std;

class Employee
{
    int employeeID;
    string employeeName;
    double salary;

public:
    void accept()
    {
        cin >> employeeID;
        cin.ignore();
        getline(cin, employeeName);
        cin >> salary;
    }

    void display()
    {
        cout << "Employee ID = " << employeeID << endl;
        cout << "Employee Name = " << employeeName << endl;
        cout << "Salary = " << salary << endl;
    }

    double getSalary()
    {
        return salary;
    }
};

int main()
{
    int n;
    double total = 0;

    cin >> n;

    Employee *employees = new Employee[n];

    for (int i = 0; i < n; i++)
        employees[i].accept();

    int highest = 0;

    for (int i = 0; i < n; i++)
    {
        employees[i].display();

        total += employees[i].getSalary();

        if (employees[i].getSalary() >
            employees[highest].getSalary())
        {
            highest = i;
        }
    }

    cout << "\nHighest Salary Employee:" << endl;
    employees[highest].display();

    cout << "Average Salary = " << total / n << endl;

    delete[] employees;

    return 0;
}