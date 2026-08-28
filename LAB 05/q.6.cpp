#include <iostream>
using namespace std;

int information(char a[])
{
    int i = 0;

    while (a[i] != '\0')
        i++;

    return i;
}

int information(char a[], char x)
{
    int count = 0;

    for (int i = 0; a[i] != '\0'; i++)
        if (a[i] == x)
            count++;

    return count;
}

int information(char a[], char x, int k)
{
    int count = 0;

    for (int i = 0; i < k && a[i] != '\0'; i++)
        if (a[i] == x)
            count++;

    return count;
}

int main()
{
    char a[100], x;
    int k;

    cout << "Enter a string: ";
    cin >> a;

    cout << "Enter character: ";
    cin >> x;

    cout << "Enter k: ";
    cin >> k;

    cout << "Length = " << information(a) << endl;
    cout << "Total occurrence = " << information(a, x) << endl;
    cout << "Occurrence in first k positions = "
         << information(a, x, k) << endl;

    return 0;
}