#include <iostream>
#include <string>
using namespace std;

class Book
{
    int bookID;
    string title;
    string author;
    double price;

public:
    void accept()
    {
        cin >> bookID;
        cin.ignore();
        getline(cin, title);
        getline(cin, author);
        cin >> price;
    }

    void display()
    {
        cout << "Book ID = " << bookID << endl;
        cout << "Book Title = " << title << endl;
        cout << "Author = " << author << endl;
        cout << "Price = " << price << endl;
    }
};

int main()
{
    Book *book = new Book;

    book->accept();
    book->display();

    delete book;

    return 0;
}