//! header guard
#ifndef BOOKOPERATIONS_H
#define BOOKOPERATIONS_H
//! Books class
class Books
{
  public:
    int book_stock[10], book_isbn_no[10], book_initial_stock[10]; /**< variable that store book stock, book ISBN number and initial stock */
    float book_price[10];                                         /**< variable that store book price */
    string book_author[10], book_name[10];                        /**< array to store book author and book name */
    int i=0; 

    void welcomemsg();                                                                              //!< declaration of welcome message function
    void addBook(string bookName, string bookAuthor, int bookStock, int bookISBN, float bookPrice); //!< declaration of add book into the library
    void display();                                                                                 //!< declaration of display all the availble books into the library
    void display(string bookAuthor);                                                                //!< declaration of display all the availble books of given book name
    void issueBook(string bookName);                                                                //!< declaration of function that used for issue book from the library
    void returnBook(string bookName);                                                               //!< declaration of function that used to return book to the library
    void deleteBook(string bookName);
};
#endif
