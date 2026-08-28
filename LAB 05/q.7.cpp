#include <iostream>
#include <cmath>
using namespace std;

int nearValue(int a, int b)
{
    return abs(a) < abs(b) ? a : b;
}

float nearValue(float a, float b)
{
    return fabs(a) < fabs(b) ? a : b;
}

int nearValue(int a[], int n)
{
    int nearest = a[0];

    for (int i = 1; i < n; i++)
    {
        if (abs(a[i]) < abs(nearest))
            nearest = a[i];
    }

    return nearest;
}

int main()
{
    int a, b, n, arr[50];
    float x, y;

    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "Nearest integer = " << nearValue(a, b) << endl;

    cout << "Enter two floats: ";
    cin >> x >> y;

    cout << "Nearest float = " << nearValue(x, y) << endl;

    cout << "Enter array size: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Nearest array value = " << nearValue(arr, n) << endl;

    return 0;
}