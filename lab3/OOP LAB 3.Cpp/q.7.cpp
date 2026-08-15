#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    int n;
    int vowels = 0;
    int consonants = 0;
    int digits = 0;
    int spaces = 0;

    cin >> n;
    cin.ignore();

    char *arr = new char[n];

    cin.getline(arr, n);

    for (int i = 0; arr[i] != '\0'; i++)
    {
        char ch = arr[i];

        if (isalpha(ch))
        {
            ch = tolower(ch);

            if (ch == 'a' || ch == 'e' || ch == 'i' ||
                ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
        else if (isdigit(ch))
        {
            digits++;
        }
        else if (ch == ' ')
        {
            spaces++;
        }
    }

    cout << "Vowels = " << vowels << endl;
    cout << "Consonants = " << consonants << endl;
    cout << "Digits = " << digits << endl;
    cout << "Spaces = " << spaces << endl;

    delete[] arr;

    return 0;
}