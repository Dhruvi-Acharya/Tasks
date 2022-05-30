/*****************************************************************************************************
 * Library System
 * functonalities: add new book into the library, search book, issue book, return book and delete book
 ******************************************************************************************************/

/*! including input output stream header file */
#include <iostream>
#include <string.h>
using namespace std;
/*! including LibBooks header file */
#include "include/CountBooks.h"

int main()
{
	enum bookOperation
	{
		addBook = 1,
		displayAllBooks = 2,
		displayBookByAuthor = 3,
		countTotalBooks = 4,
		countParticularBook = 5,
		issueBook = 6,
		returnBook = 7,
		deleteBook = 8,
		quit = 9
	};
	Books *ptrBook;
	CountBooks objBook; /**< created object of CountBooks */
	ptrBook = &objBook;

	string bookName, bookAuthor;
	int bookStock, bookISBNno;
	float bookPrice;

	int choice; /**< for user choice to perform operation*/

	do
	{
		ptrBook->welcomemsg(); /*! printing welcome message */

		cout << endl
			 << "1. Enter book into the Library\n2. Disply all the books\n3. Display all books of given author\n4. Display total number of books in the library\n5. Display total number of available by book name\n6. Issue Book\n7. Return Book\n8. Delete Book\n9. Exit\n";

		cout << "\nEnter your choice: ";
		cin >> choice; /*! taking choice from user */
		cout << endl;

		switch (choice)
		{
		case addBook:
			cout << "Enter book name: ";
			cin >> bookName;
			cout << "Enter book author: ";
			cin >> bookAuthor;
			cout << "Enter book stock: ";
			cin >> bookStock;
			cout << "Enter book ISBN no.: ";
			cin >> bookISBNno;
			cout << "Enter book price: ";
			cin >> bookPrice;

			objBook.addBook(bookName, bookAuthor, bookStock, bookISBNno, bookPrice); /*! add book into the library */
			break;

		case displayAllBooks:
			objBook.display(); /*! display all books information from the library */
			break;

		case displayBookByAuthor:
			cout << "Enter Author name: ";
			cin >> bookAuthor;

			objBook.display(bookAuthor); /*! display infromation book by book author */
			break;

		case countTotalBooks:
			objBook.countBook(); /*! adisplay total number of books availble in the library */
			break;

		case countParticularBook:
			cout << "Enter book name which you want to show count: ";
			cin >> bookName;
			objBook.countBook(bookName); /*! display particluar book name count */
			break;

		case issueBook:
			cout << "Enter book name which you want to issue: ";
			cin >> bookName;

			objBook.issueBook(bookName); /*! issue book from the library */
			break;

		case returnBook:
			cout << "Enter book name which you want to return: ";
			cin >> bookName;

			objBook.returnBook(bookName); /*! return book to the library */
			break;

		case deleteBook:
			cout << "Enter book name which you want to delete: ";
			cin >> bookName;

			objBook.deleteBook(bookName); /*! delete book from the library */
			break;

		case quit:
			cout << "Thank you for visiting us" << endl;
			exit(0); /*! quitting user from the application*/

		default:
			cout << "Please Enter valid choice" << endl;
		}
	} while (choice != 9);
	return 0;
}