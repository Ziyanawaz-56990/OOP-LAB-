#include <iostream>
using namespace std;

int area(int s)
{
    return s * s;
}

int area(int l, int b)
{
    return l * b;
}

float area(float r)
{
    return 3.14f * r * r;
}

int main()
{
    int s, l, b;
    float r;

    cout << "Enter side of square: ";
    cin >> s;

    cout << "Enter length and breadth: ";
    cin >> l >> b;

    cout << "Enter radius: ";
    cin >> r;

    cout << "Square area = " << area(s) << endl;
    cout << "Rectangle area = " << area(l, b) << endl;
    cout << "Circle area = " << area(r) << endl;

    return 0;
}