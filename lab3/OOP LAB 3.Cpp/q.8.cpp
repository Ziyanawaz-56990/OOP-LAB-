#include <iostream>
using namespace std;

void accept(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

int calculateSum(int *arr, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    return sum;
}

int findSmallest(int *arr, int n)
{
    int small = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < small)
            small = arr[i];
    }

    return small;
}

int findLargest(int *arr, int n)
{
    int large = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > large)
            large = arr[i];
    }

    return large;
}

void display(int sum, int small, int large)
{
    cout << "Sum = " << sum << endl;
    cout << "Smallest = " << small << endl;
    cout << "Largest = " << large << endl;
}

int main()
{
    int n;

    cin >> n;

    int *arr = new int[n];

    accept(arr, n);

    int sum = calculateSum(arr, n);
    int small = findSmallest(arr, n);
    int large = findLargest(arr, n);

    display(sum, small, large);

    delete[] arr;

    return 0;
}