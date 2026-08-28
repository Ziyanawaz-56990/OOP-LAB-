#include <iostream>
using namespace std;

int process(int a[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

float process(float a[], int n)
{
    float sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

int process(int a[], int n, int k)
{
    int sum = 0;

    for (int i = 0; i < k; i++)
        sum += a[i];

    return sum;
}

int main()
{
    int a[50], n, k;
    float b[50];

    cout << "Enter size of integer array: ";
    cin >> n;

    cout << "Enter integer elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter size of float array: ";
    cin >> k;

    cout << "Enter float elements: ";
    for (int i = 0; i < k; i++)
        cin >> b[i];

    cout << "Enter k: ";
    int x;
    cin >> x;

    cout << "Integer sum = " << process(a, n) << endl;
    cout << "Float sum = " << process(b, k) << endl;
    cout << "First k elements sum = " << process(a, n, x) << endl;

    return 0;
}