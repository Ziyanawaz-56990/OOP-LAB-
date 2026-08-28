##include <iostream>
using namespace std;

void check(int n)
{
    if (n > 0)
        cout << "Positive" << endl;
    else if (n < 0)
        cout << "Negative" << endl;
    else
        cout << "Zero" << endl;
}

void check(char c)
{
    if (c >= 'A' && c <= 'Z')
        cout << "Uppercase" << endl;
    else if (c >= 'a' && c <= 'z')
        cout << "Lowercase" << endl;
    else
        cout << "Not a letter" << endl;
}

void check(char a[], int n, char x)
{
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            found = true;
            break;
        }
    }

    if (found)
        cout << "Character found" << endl;
    else
        cout << "Character not found" << endl;
}

int main()
{
    int n, size;
    char c, x, a[50];

    cout << "Enter integer: ";
    cin >> n;
    check(n);

    cout << "Enter character: ";
    cin >> c;
    check(c);

    cout << "Enter array size: ";
    cin >> size;

    cout << "Enter characters: ";
    for (int i = 0; i < size; i++)
        cin >> a[i];

    cout << "Enter character to search: ";
    cin >> x;

    check(a, size, x);

    return 0;
}
