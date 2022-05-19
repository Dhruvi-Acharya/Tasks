//!header guard
#ifndef OPERATIONS_H
#define OPERATIONS_H

//! Books class
class Books{
public:
  int stock,isbn_no,initial_stock; /**< variable that store book stock, book ISBN number and initial stock */
  float price; /**< variable that store book price */
  char author[10],book_name[10]; /**< array to store book author and book name */

  void welcomemsg(); //!< declaration of printwekcomeMessage function
  void addBook(); //!< declaration of add book into the library
  void display(); //!< declaration of display all the availble books into the library
  void display(char title[],char author[]); //!< declaration of display all the availble books of given author and book title
  void issueBook(); //!< declaration of function that used for issue book from the library
  void returnBook(); //!< declaration of function that used to return book to the library
};

#endif