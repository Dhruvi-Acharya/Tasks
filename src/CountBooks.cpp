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
        cout << "Library is empty" << endl;
    }
    else
    {
        int flag = 0;
        int count = 0;
        for (it = bookList.begin(); it != bookList.end(); it++)
        {
            Book ptr = *it;
            count += ptr.book_stock;
            flag = 1;
            cout<< ptr.book_name << " book count: "<<ptr.book_stock<<endl;
        }
        if (0 != flag)
            cout << "\nTotal number of books in the library is: " << count << endl;
    }
}

void CountBooks::countBook(string bookName) //!< definition of count book given by book name
{
    if (i == 0)
    {
        cout << "\nLibrary is empty" << endl;
    }
    else
    {
        int is_book_found = 0;
        int count = 0;
        for (it = bookList.begin(); it != bookList.end(); it++)
        {
            Book ptr = *it;
            if (ptr.book_name == bookName) /*!condition to check user entered id match to Pid array or not if it match account info will be shown*/
            {
                cout << "\nBook Name\tStock\tBook Issued" << endl;
                count += ptr.book_stock;
                is_book_found = 1;
                cout << ptr.book_name << "\t\t" << ptr.book_stock << "\t\t" << ptr.book_issued << endl;
            }
        }
        if (0 == is_book_found)
        {
            cout << "\nBook not found by given book name" << endl;
        }
        else
        {
            cout << "\nTotal number of books of " << bookName << " is: " << count << endl;
        }
    }
}