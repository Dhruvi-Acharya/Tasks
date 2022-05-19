/*!including input output stream header file*/
#include <iostream>
using namespace std;
/*!including operations header file*/
#include "../include/Books.h"

void Books::welcomemsg(){ /*!Runtime polymorphism*/ //!< definition of printwelcomeMessage function
cout<<"\n------------Welcome to the Library------------\n";
}

void Books::addBook(){ //!< definition of add book into the library
	cout<<"Enter Book Name: ";
	cin>>book_name;

	cout<<"Enter Book ISBN number: ";
	cin>>isbn_no;

	cout<<"Enter Book Price: ";
	cin>>price;

	cout<<"Enter Book Author Name: ";
	cin>>author;

	cout<<"Enter Book Stock: ";
	cin>>stock;

	initial_stock=stock;
}

void Books::display(){ //!< definition of display all the book from the library
	cout<<book_name<<"\t\t"<<isbn_no<<"\t\t"<<price<<"\t\t"<<author<<"\t\t"<<stock<<endl;
}

void Books::display(char title[],char author[]){ //!< definition of display book of given author and title
	cout<<title<<"\t\t"<<author<<"\t\t"<<price<<"\t\t"<<isbn_no<<"\t\t"<<stock<<endl;
}

void Books::issueBook(){ //!< definition of issue a book from the library
	if(stock==0){ /*check if the stock of book is 0 or not */
		cout<<"You can not isse book, No book availble!!!"<<endl;
	}
	else{
		stock--;
		cout<<"Book Issued Successfully!!!"<<endl;
	}
}

void Books::returnBook(){ //!< definition of return a book to the library
	if(stock==initial_stock){ /*check if the initial stock of the book is same as stock then the book isn't issued but user try to return it */
		cout<<"You can't return book, because you didn't issued book"<<endl;
	}
	else{
		stock++;
		cout<<"Book Returned Successfully!!!"<<endl;
	}
}