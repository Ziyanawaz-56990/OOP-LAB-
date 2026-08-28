#include <iostream>
using namespace std;

void update(int &x, int n)
{
    x += n;
}

void update(float &x, float n)
{
    x += n;
}

void update(int a[], int n, int amount)
{
    for (int i = 0; i < n; i++)
        a[i] += amount;
}

int main()
{
    int x, n, size, a[50];
    float y, amount;

    cout << "Enter integer and amount: ";
    cin >> x >> n;

    cout << "Before: " << x << endl;
    update(x, n);
    cout << "After: " << x << endl;

    cout << "Enter float and amount: ";
    cin >> y >> amount;

    cout << "Before: " << y << endl;
    update(y, amount);
    cout << "After: " << y << endl;

    cout << "Enter array size: ";
    cin >> size;

    cout << "Enter elements: ";
    for (int i = 0; i < size; i++)
        cin >> a[i];

    cout << "Enter amount: ";
    cin >> n;

    cout << "Before: ";
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";

    update(a, size, n);

    cout << "\nAfter: ";
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";

    return 0;
}