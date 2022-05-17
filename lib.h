class Books{
public:
	int stock,isbn_no,istock;
	float price;
	char author[10],book_name[10];

	void addBook(); // this function add book into the library
	void display(); // this function will display all the availble books into the library
	void issueBook(); // this function used for issue book from the library
	void returnBook(); // this function used to return book to the library
	int countBook(); /// this function will count total number of book availble into the library
};

void Books::addBook(){
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
	istock=stock;
}

void Books::display(){
	cout<<book_name<<"\t\t"<<isbn_no<<"\t\t"<<price<<"\t\t"<<author<<"\t\t"<<stock<<endl;
}

void Books::issueBook(){
	if(stock==0){
		cout<<"You can not isse book, No book availble!!!"<<endl;
	}
	else{
		stock--;
		cout<<"Book Issued Successfully!!!"<<endl;
	}
}

void Books::returnBook(){
	if(stock==istock){
		cout<<"You can't return book, because you didn't issued book"<<endl;
	}
	else{
		stock++;
		cout<<"Book Returned Successfully!!!"<<endl;
	}
}

int Books::countBook(){
	return stock;
}
