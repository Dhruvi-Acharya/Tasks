/*!including input output stream header file*/
#include <iostream>
using namespace std;
/*!including LibBooks header file*/
#include "../include/CountBooks.h"

void CountBooks::welcomemsg() //!< definition of welcome message function
{
    cout << "\n------------Welcome------------\n";
}

void CountBooks::countBook() //!< definition of count total number of books available to the library
{
    if (i == 0)
    {
        cout << "\nLibrary is empty" << endl;
    }
    else
    {
        int count = 0;
        for (int j = 0; j < i; j++)
        {
            count += book_stock[j];
        }
        cout << "\nTotal number of books " << count << endl;
    }
}

void CountBooks::countBook(string bookName) //!< definition of count book given by book name
{
    int is_book_found = 0;
    if (i == 0)
    {
        cout << "\nLibrary is empty" << endl;
    }
    else
    {
        int count = 0;
        for (int j = 0; j < i; j++)
        {
            if (book_name[j] == bookName)
            {
                is_book_found = 1;
                count = book_stock[j];
            }
        }
        if (is_book_found == 0)
        {
            cout << "\nbook not found by given book name" << endl;
        }
        else
        {
            cout << "\nTotal number of books of given book name is: " << count << endl;
        }
    }
}