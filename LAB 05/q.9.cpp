#include <iostream>
using namespace std;

void inspect(int x)
{
    cout << "Integer value = " << x << endl;
}

void inspect(int *p)
{
    cout << "Pointer value = " << *p << endl;
}

void inspect(int *p, int n)
{
    cout << "Array elements: ";

    for (int i = 0; i < n; i++)
        cout << *(p + i) << " ";

    cout << endl;
}

int main()
{
    int x, n, a[50];

    cout << "Enter integer: ";
    cin >> x;

    inspect(x);
    inspect(&x);

    cout << "Enter array size: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    inspect(a, n);

    return 0;
}