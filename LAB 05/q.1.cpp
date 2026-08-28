#include <iostream>
using namespace std;

int convert(int km)
{
    return km * 1000;
}

int convert(long m)
{
    return m * 100;
}

float convert(float km)
{
    return km * 1000;
}

int main()
{
    int km, m;
    float fkm;

    cout << "Enter distance in km: ";
    cin >> km;

    cout << "Enter distance in meters: ";
    cin >> m;

    cout << "Enter floating distance in km: ";
    cin >> fkm;

    cout << "Meters = " << convert(km) << endl;
    cout << "Centimeters = " << convert((long)m) << endl;
    cout << "Meters = " << convert(fkm) << endl;

    return 0;
}