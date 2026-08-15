#include <iostream>
using namespace std;

int main()
{
    int n, search, position = -1;

    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> search;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == search)
        {
            position = i;
            break;
        }
    }

    if (position != -1)
        cout << "Element found at position " << position + 1 << endl;
    else
        cout << "Element not found" << endl;

    delete[] arr;

    return 0;
}