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
        book_name[i] = bookName;
        book_author[i] = bookAuthor;
        book_stock[i] = bookStock;
        book_isbn_no[i] = bookISBN;
        book_price[i] = bookPrice;
        book_initial_stock[i] = bookStock;
        i++;
        cout << "\nBook added successfully" << endl;
    }
    else
    {
        for (int j = 0; j < i; j++)
        {
            if (book_name[j] == bookName)
            {
                cout << "\nYou cannot add another book with the same book name" << endl;
                break;
            }
            else
            {
                book_name[i] = bookName;
                book_author[i] = bookAuthor;
                book_stock[i] = bookStock;
                book_isbn_no[i] = bookISBN;
                book_price[i] = bookPrice;
                book_initial_stock[i] = bookStock;
                i++;
                cout << "\nBook added successfully" << endl;
                break;
            }
        }
    }
}

void Books::display() //!< definition of display all the book from the library
{ 
    if (i == 0)
    {
        cout << "\nLibrary is empty" << endl;
    }
    else
    {
        cout<<"\nBook name "<<"\t Book ISBN No. "<<"\t Book Price "<<"\t Author "<<"\t Stock" <<endl;
        
        for (int j = 0; j < i; j++)
            cout << book_name[j] << "\t\t" << book_isbn_no[j] << "\t\t" << book_price[j] << "\t\t" << book_author[j] << "\t\t" << book_stock[j] << endl;
    }
}

void Books::display(string bookAuthor) //!< definition of display book by given book author 
{ 
    int is_book_found = 0; 
    if (i == 0)
    {
        cout << "\nLibrary is empty" << endl;
    }
    else
    {
        
        
        for (int j = 0; j < i; j++)
        {
            if (book_author[j] == bookAuthor)
            {
                if(is_book_found==0){
                    cout<<"\nBook name "<< "\t Book ISBN No. "<< "\t Book Price "<< "\t Author "<< "\t Stock" << endl;
                }
                is_book_found = 1;

                cout << book_name[j] << "\t\t" << book_isbn_no[j] << "\t\t" << book_price[j] << "\t\t" << book_author[j] << "\t\t" << book_stock[j] << endl;
            }
        }

        if (is_book_found == 0)
        {
            cout << "\n No book found by given author name" << endl;
        }
    }
}

void Books::issueBook(string bookName) //!< definition of issue a book from the library
{
    int is_book_found = 0;
    if (i == 0)
    {
        cout << "\nLibrary is empty" << endl;
    }
    else
    {
        for (int j = 0; j < i; j++)
        {
            if (book_name[j] == bookName)
            {

                is_book_found = 1;

                if (book_stock[j] == 0) /*check if the stock of book is 0 or not */
                { 
                    cout << "\nYou can not isse book, No book availble!!!" << endl;
                }
                else
                {
                    book_stock[j]--;
                    cout << "\nBook Issued Successfully!!!" << endl;
                }
            }
        }
        if (is_book_found == 0)
        {
            cout << "\nBook not found" << endl;
        }
    }
}

void Books::returnBook(string bookName) //!< definition of return a book to the library
{ 
    int is_book_found = 0;
    if (i == 0)
    {
        cout << "\nLibrary is empty" << endl;
    }
    else
    {
        for (int j = 0; j < i; j++)
        {
            if (book_name[j] == bookName)
            {
                is_book_found = 1;
                if (book_stock[j] == book_initial_stock[j]) /*check if the initial stock of the book is same as stock then the book isn't issued but user try to return it */
                { 
                    cout << "\nYou can't return book, because you didn't issued book" << endl;
                }
                else
                {
                    book_stock[j]++;
                    cout << "\nBook Returned Successfully!!!" << endl;
                }
            }
        }
        if (is_book_found == 0)
        {
            cout << "\nBook not found" << endl;
        }
    }
}

void Books::deleteBook(string bookName) //!< definition of delete a book from the library
{
    int is_book_found = 0;
    if (i == 0)
    {
        cout << "\nLibrary is empty" << endl;
    }
    else
    {
        for (int j = 0; j < i; j++)
        {
            if (book_name[j] == bookName)
            {
                is_book_found = 1;
                for (int k = j; k < i; k++)
                {
                    book_name[j] = book_name[j + 1];
                    book_author[j] = book_author[j + 1];
                    book_stock[j] = book_stock[j + 1];
                    book_initial_stock[j] = book_initial_stock[j + 1];
                    book_isbn_no[j] = book_isbn_no[j + 1];
                    book_price[j] = book_price[j + 1];
                }
                cout << "\nBook deleted successfully" << endl;
                i = i - 1;
            }
        }
        if (is_book_found == 0)
        {
            cout << "\nBook not found" << endl;
        }
    }
}