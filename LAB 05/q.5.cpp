#include <iostream>
using namespace std;

void swapData(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapData(float &a, float &b)
{
    float temp = a;
    a = b;
    b = temp;
}

void swapData(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b, x, y;
    float p, q;

    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "Before: " << a << " " << b << endl;
    swapData(a, b);
    cout << "After: " << a << " " << b << endl;

    cout << "Enter two floats: ";
    cin >> p >> q;

    cout << "Before: " << p << " " << q << endl;
    swapData(p, q);
    cout << "After: " << p << " " << q << endl;

    cout << "Enter two integers for pointer swap: ";
    cin >> x >> y;

    cout << "Before: " << x << " " << y << endl;
    swapData(&x, &y);
    cout << "After: " << x << " " << y << endl;

    return 0;
}