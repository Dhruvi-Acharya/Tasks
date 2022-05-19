/*! including input output stream header file */
#include <iostream>
#include<string.h>
using namespace std;
/*! including LibBooks header file */
#include "include/LibBooks.h"

int main(){

	LibBooks b[10]; /**< created array of 10 books */
  	int choice; /**< choice variable to take choice that which operation user want to perform */
	int tmp; /**< tmp variable for temporary */
	int i=0;
  	int count = 0; /**< count variable to count the total number of books */
  	char search_author[10],search_title[10]; /**< serch_author variable to search book by author name  */

	Books *ptr; 
	LibBooks obj2;
	ptr=&obj2;

	do{

    	ptr->welcomemsg(); /*! printing welcome message */

		cout<<endl<<"Library Menu"<<endl;

		cout<<"1. Enter book into the Library\n2. Display all the books\n3. Display all books of given author\n4. Display total number of books in the library\n5. Search book by title\n6. Issue Book\n7. Display Book by title and author\n8. Return Book\n9. Delete Book\n10. Exit\n";

		cout<<"Enter your choice: ";
    	cin>>choice; /*! taking choice from user */

		switch(choice){
			case 1:
      			b[i].addBook(); /*! add book into the library */
				i++;
				cout<<"Book added to the library Successfully!!!"<<endl;
				break;

			case 2:
				if(i==0){ 
					cout<<"Library is empty, No book found!!!"<<endl;
				}
				else{
					cout<<"Book name "<<"\t Book ISBN No. "<<"\t Book Price "<<"\t Author "<<"\t Stock"<<endl;
					for(int j=0;j<i;j++){
	          			b[j].display(); /*! display books from the library */
					}
				}
				break;

			case 3:
				cout<<"Enter Author name: ";
				cin>>search_author;

				tmp=0;

				if(i==0){
					cout<<"Library is empty, No book found!!!\n";
				}
				else{
					cout<<"Book name "<<"\t Book ISBN No. "<<"\t Book Price "<<"\t Author "<<"\t Stock"<<endl;
					for(int j=0;j<i;j++){
	          			if(strcmp(b[j].author,search_author)==0){ /*! comparing weather author given by user is matched with the book available in the library */
							tmp=1;
							b[j].display();
						}
					}
					if(tmp==0){
						cout<<"No book availble of given author!!!"<<endl;
					}
				}
				break;

			case 4:
				if(i==0){
					cout<<"No books in the library\n";
				}
				else{
					count=0;
					for(int j=0;j<i;j++){
						count = count + b[j].countBook();
					}
					cout<<"Total number of books availble in the library: "<<count<<endl;
				}
				break;

			case 5:
				if(i==0){
					cout<<"No books in the library"<<endl;
				}
				else{
					cout<<"Enter book title:  ";
					cin>>search_title;
					tmp=0;
					cout<<"Book name "<<"\t Book ISBN No. "<<"\t Book Price "<<"\t Author "<<"\t Stock"<<endl;
					for(int j=0;j<i;j++){
		          		if(strcmp(b[j].book_name,search_title)==0){ /*! compare book title with the user inputed title */
							tmp=1;
							b[j].display();
						}
					}
					if(tmp==0){
						cout<<"No book availble with given title"<<endl;
					}
				}
				break;

			case 6:
				cout<<"Enter book title which you want to issue: ";
				cin>>search_title;

				for(int j=0;j<i;j++){
					if(strcmp(b[j].book_name,search_title)==0){
						tmp=1;
						b[j].issueBook();
					}
				}
				if(tmp==0){
					cout<<"book not found"<<endl;
				}
				break;

			case 7:
				if(i==0){
					cout<<"No books in the library"<<endl;
				}
				else{
					cout<<"Enter book title: ";
					cin>>search_title;
					cout<<"Enter book author: ";
					cin>>search_author;

					tmp=0;
					cout<<"Book name "<<"\t Book Author. "<<"\t Book Price "<<"\t ISBN No. "<<"\t Stock"<<endl;

					for(int j=0;j<i;j++){
			        	if(strcmp(b[j].book_name,search_title)==0 && strcmp(b[j].author,search_author)==0){ /*! comparison with book title and author */
							tmp=1;
							b[j].display(search_title,search_author);
						}
					}

					if(tmp==0){
						cout<<"No book availble with given title and author"<<endl;
					}
				}
				break;
			case 8:
				cout<<"Enter book title which you want to return: ";
				cin>>search_title;
				tmp=0;
				for(int j=0;j<i;j++){
					if(strcmp(b[j].book_name,search_title)==0){
						tmp=1;
						b[j].returnBook();
					}
				}
				if(tmp==0){
					cout<<"book not found"<<endl;
				}
				break;

			case 9:
				cout<<"Enter book title which you want to delete: ";
				cin>>search_title;
				tmp=0;

				for(int j=0;j<i;j++){
					if(strcmp(b[j].book_name,search_title)==0){ /*! compare book title to delete a book from the library */
						tmp=1;
						for(int k=j;k<i;k++){
							b[j]=b[j+1];
						}
						cout<<"Book deleted successfully"<<endl;
						i=i-1;
					}
				}
				if(tmp==0){
					cout<<"book not found"<<endl;
				}
				break;

			case 10:
				exit(0); /*! quitting user from the application*/

			default:
				cout<<"Please Enter valid choice"<<endl;
		}
	}while(choice!=10);

	return 0;
}