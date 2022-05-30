/*!including input output stream header file*/
#include <iostream>
using namespace std;
/*!including operations header file*/
#include "../include/Books.h"

void Books::welcomemsg() //!< definition of welcome message function
{
    cout << "\n------------Welcome to the Library------------\n";
}

void Books::addBook(string bookName, string bookAuthor, int bookStock, int bookISBN, float bookPrice) //!< definition of add book into the library
{
    if (i == 0)
    {
        bookObj.book_name = bookName;
        bookObj.book_author = bookAuthor;
        bookObj.book_stock = bookStock;
        bookObj.book_isbn_no = bookISBN;
        bookObj.book_price = bookPrice;
        bookObj.book_initial_stock = bookStock;
        bookList.push_back(bookObj);
        i++;
        cout << endl
             << bookName << " book added to the library successfully" << endl;
    }
    else
    {
        for (it = bookList.begin(); it != bookList.end(); it++)
        {
            Book ptr = *it;
            if (ptr.book_name == bookName || ptr.book_isbn_no == bookISBN)
            {
                cout << "\nYou cannot add another book with the same book name or same ISBN number" << endl;
                break;
            }
            else
            {
                bookObj.book_name = bookName;
                bookObj.book_author = bookAuthor;
                bookObj.book_stock = bookStock;
                bookObj.book_isbn_no = bookISBN;
                bookObj.book_price = bookPrice;
                bookObj.book_initial_stock = bookStock;
                bookList.push_back(bookObj);
                i++;
                cout << endl
                     << bookName << " book added to the library successfully" << endl;
                break;
            }
        }
    }
}

void Books::display() //!< definition of display all the book from the library
{
    if (i == 0)
    {
        cout << "Library is empty" << endl;
    }
    else
    {

        int flag = 0;
        cout << "Book Name "
             << "\t Book ISBN No. "
             << "\t Book Price "
             << "\t Author "
             << "\t Stock"
             << "\t Book Issued" << endl;
        for (it = bookList.begin(); it != bookList.end(); it++)
        {
            Book ptr = *it;
            cout << ptr.book_name << "\t\t" << ptr.book_isbn_no << "\t\t" << ptr.book_price << "\t\t" << ptr.book_author << "\t\t" << ptr.book_stock << "\t\t" << ptr.book_issued << endl;
            flag = 1;
        }
    }
}

void Books::display(string bookAuthor) //!< definition of display book by given book author
{
    if (i == 0)
    {
        cout << "\nLibrary is empty" << endl;
    }
    else
    {

        int is_book_found = 0;

        for (it = bookList.begin(); it != bookList.end(); it++)
        {
            Book ptr = *it;
            if (ptr.book_author == bookAuthor) /*!condition to check user entered id match to Pid array or not if it match account info will be shown*/
            {
                if (0 == is_book_found)
                {
                    cout << "\nBook Name "
                         << "\t Book ISBN No. "
                         << "\t Book Price "
                         << "\t Author "
                         << "\t Stock"
                         << "\t Book Issued" << endl;
                }
                cout << ptr.book_name << "\t\t" << ptr.book_isbn_no << "\t\t" << ptr.book_price << "\t\t" << ptr.book_author << "\t\t" << ptr.book_stock << "\t\t" << ptr.book_issued << endl;
                is_book_found = 1;
            }
        }
        if (0 == is_book_found)
            cout << "\nNo book found by given author name" << endl;
    }
}

void Books::issueBook(string bookName) //!< definition of issue a book from the library
{
    if (i == 0)
    {
        cout << "\nLibrary is empty" << endl;
    }
    else
    {
        int is_book_found = 0;
        for (it = bookList.begin(); it != bookList.end(); it++)
        {
            Book ptr = *it;
            if (ptr.book_name == bookName) /*!condition to check user entered id match to Pid array or not if it match account info will be shown*/
            {
                is_book_found = 1;
                if (ptr.book_stock == 0) /*check if the stock of book is 0 or not */
                {
                    cout << "\nYou can not issue book, No book availble!!!" << endl;
                    cout << "\nBook Name "
                         << "\t Book ISBN No. "
                         << "\t Book Price "
                         << "\t Author "
                         << "\t Stock"
                         << "\t Book Issued" << endl;
                    cout << ptr.book_name << "\t\t" << ptr.book_isbn_no << "\t\t" << ptr.book_price << "\t\t" << ptr.book_author << "\t\t" << ptr.book_stock << "\t\t" << ptr.book_issued << endl;
                }
                else
                {
                    ptr.book_stock--;
                    ptr.book_issued++;
                    bookList.emplace(it, ptr); /*!inserting updated value into list*/
                    bookList.erase(it);
                    cout << "\nBook Issued Successfully!!!" << endl;
                    cout << "\nBook Name "
                         << "\t Book ISBN No. "
                         << "\t Book Price "
                         << "\t Author "
                         << "\t Stock"
                         << "\t Book Issued" << endl;
                    cout << ptr.book_name << "\t\t" << ptr.book_isbn_no << "\t\t" << ptr.book_price << "\t\t" << ptr.book_author << "\t\t" << ptr.book_stock << "\t\t" << ptr.book_issued << endl;
                }
                break;
            }
        }
        if (0 == is_book_found)
            cout << "\nBook not found" << endl;
    }
}

void Books::returnBook(string bookName) //!< definition of return a book to the library
{
    if (i == 0)
    {
        cout << "\nLibrary is empty" << endl;
    }
    else
    {
        int is_book_found = 0;
        for (it = bookList.begin(); it != bookList.end(); it++)
        {
            Book ptr = *it;
            if (ptr.book_name == bookName) /*!condition to check user entered id match to Pid array or not if it match account info will be shown*/
            {
                is_book_found = 1;
                if (ptr.book_stock == ptr.book_initial_stock) /*check if the stock of book is 0 or not */
                {
                    cout << "\nYou can't return book, because you didn't issued book" << endl;
                }
                else
                {
                    ptr.book_stock++;
                    ptr.book_issued--;
                    bookList.emplace(it, ptr); /*!inserting updated value into list*/
                    bookList.erase(it);
                    cout << "\nBook Returned Successfully!!!" << endl;
                    cout << "\nBook Name "
                         << "\t Book ISBN No. "
                         << "\t Book Price "
                         << "\t Author "
                         << "\t Stock"
                         << "\t Book Issued" << endl;
                    cout << ptr.book_name << "\t\t" << ptr.book_isbn_no << "\t\t" << ptr.book_price << "\t\t" << ptr.book_author << "\t\t" << ptr.book_stock << "\t\t" << ptr.book_issued << endl;
                }
                break;
            }
        }
        if (0 == is_book_found)
            cout << "\nBook not found" << endl;
    }
}

void Books::deleteBook(string bookName) //!< definition of delete a book from the library
{
    if (i == 0)
    {
        cout << "\nLibrary is empty" << endl;
    }
    else
    {
        int is_book_found = 0;
        for (it = bookList.begin(); it != bookList.end(); it++)
        {
            Book ptr = *it;
            if (ptr.book_name == bookName) /*!condition to check user entered id match to Pid array or not if it match account info will be shown*/
            {
                is_book_found = 1;
                bookList.erase(it); /*!deleting information from list of particular id*/
                cout << "Book deleted from the library sucessfully !!!" << endl
                     << endl;
                i--;
                break;
            }
        }
        if (0 == is_book_found)
            cout << "\nNo book found by given book name" << endl;
    }
}