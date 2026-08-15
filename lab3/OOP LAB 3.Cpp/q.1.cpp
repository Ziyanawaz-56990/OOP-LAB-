#include <iostream>
using namespace std;

int main()
{
    int *a = new int;
    int *b = new int;

    cin >> *a >> *b;

    cout << "Sum = " << *a + *b << endl;
    cout << "Difference = " << *a - *b << endl;
    cout << "Product = " << *a * *b << endl;

    if (*b != 0)
        cout << "Quotient = " << (double)*a / *b << endl;
    else
        cout << "Quotient = Cannot divide by zero" << endl;

    delete a;
    delete b;

    return 0;
}