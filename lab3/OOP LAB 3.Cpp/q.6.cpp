#include <iostream>
#include <string>
using namespace std;

class Product
{
    int productID;
    string productName;
    double price;
    int quantity;

public:
    void accept()
    {
        cin >> productID;
        cin.ignore();
        getline(cin, productName);
        cin >> price >> quantity;
    }

    double getCost()
    {
        return price * quantity;
    }

    void display()
    {
        cout << "Product ID = " << productID << endl;
        cout << "Product Name = " << productName << endl;
        cout << "Price = " << price << endl;
        cout << "Quantity = " << quantity << endl;
        cout << "Total Cost = " << getCost() << endl;
    }
};

int main()
{
    int n;
    double total = 0;

    cin >> n;

    Product *products = new Product[n];

    for (int i = 0; i < n; i++)
        products[i].accept();

    for (int i = 0; i < n; i++)
    {
        products[i].display();
        total += products[i].getCost();
    }

    cout << "Overall Inventory Value = " << total << endl;

    delete[] products;

    return 0;
}