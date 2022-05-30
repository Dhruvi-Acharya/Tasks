//! header guard
#ifndef BOOKOPERATIONS_H
#define BOOKOPERATIONS_H
#include <list>
#include <iterator>

//! Books class
class Books
{
protected:
  struct Book
  {
    int book_stock, book_isbn_no, book_initial_stock, book_issued = 0; /**< variable that store book stock, book ISBN number and initial stock */
    float book_price;                                                  /**< variable that store book price */
    string book_author, book_name;                                     /**< array to store book author and book name */
  } bookObj;

  list<Book> bookList; //!< STL list to datatype Book
  list<Book>::iterator it;
  int i = 0;

public:
  void welcomemsg();                                                                              //!< declaration of welcome message function
  void addBook(string bookName, string bookAuthor, int bookStock, int bookISBN, float bookPrice); //!< declaration of add book into the library
  void display();                                                                                 //!< declaration of display all the availble books into the library
  void display(string bookAuthor);                                                                //!< declaration of display all the availble books of given book name
  void issueBook(string bookName);                                                                //!< declaration of function that used for issue book from the library
  void returnBook(string bookName);                                                               //!< declaration of function that used to return book to the library
  void deleteBook(string bookName);
};
#endif