#include <iostream>
using namespace std;

int main()
{
    int m, n;

    cin >> m >> n;

    int **a = new int*[m];
    int **b = new int*[m];
    int **sum = new int*[m];

    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
        b[i] = new int[n];
        sum[i] = new int[n];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> b[i][j];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            sum[i][j] = a[i][j] + b[i][j];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << sum[i][j] << " ";

        cout << endl;
    }

    for (int i = 0; i < m; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] sum[i];
    }

    delete[] a;
    delete[] b;
    delete[] sum;

    return 0;
}