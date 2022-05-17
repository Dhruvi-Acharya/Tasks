#include<iostream>
#include<string.h>

using namespace std;

#include "lib.h"

int main(){

	Books b[10];
	int ch,i=0,tmp,count=0;
	char search_author[10],title[10];

	do{

		cout<<"\n------------Welcome to the Library------------\n";

		cout<<endl<<"Library Menu"<<endl;

		cout<<"1. Enter book into the Library\n2. Display all the books\n3. Display all books of given author\n4. Display total number of books in the library\n5. Search book by title\n6. Issue Book\n7. Return Book\n8. Delete Book\n9. Exit\n";

		cout<<"Enter your choice: ";
		cin>>ch;

		switch(ch){
			case 1:
			b[i].addBook();
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

					b[j].display();

						//cout<<b[j].book_name<<"\t"<<b[j].author<<"\t"<<b[j].isbn_no<<"\t"<<b[j].price<<"\t"<<b[j].stock<<endl;
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
					if(strcmp(b[j].author,search_author)==0){
						
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
				cin>>title;
				tmp=0;
				cout<<"Book name "<<"\t Book ISBN No. "<<"\t Book Price "<<"\t Author "<<"\t Stock"<<endl;
				for(int j=0;j<i;j++){
					if(strcmp(b[j].book_name,title)==0){
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
			cin>>title;

			for(int j=0;j<i;j++){
				if(strcmp(b[j].book_name,title)==0){
					tmp=1;
					b[j].issueBook();
						//b[j].display();
				}
			}

			if(tmp==0){
				cout<<"book not found"<<endl;
			}
			break;

			case 7:
			cout<<"Enter book title which you want to return: ";
			cin>>title;

			for(int j=0;j<i;j++){
				if(strcmp(b[j].book_name,title)==0){
					tmp=1;
					b[j].returnBook();
				}
			}
			if(tmp==0){
				cout<<"book not found"<<endl;
			}
			break;

			case 8:
			cout<<"Enter book title which you want to delete: ";
			cin>>title;
			tmp=0;

			for(int j=0;j<i;j++){
				if(strcmp(b[j].book_name,title)==0){
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

			case 9:
				exit(0);

			default:
				cout<<"Please Enter valid choice"<<endl;
		}

	}while(ch!=9);

	return 0;
}