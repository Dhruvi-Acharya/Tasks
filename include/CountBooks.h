/*!including operations header file*/
#include "Books.h"
//!header guard
#ifndef COUNTBOOKS_H
#define COUNTBOOKS_H
/*!class CountBooks inheriting the class Books*/
class CountBooks: public Books {
  public:
    void welcomemsg();                //!< declaration of print welcome message function
    void countBook();                 //!< declaration of count total books into the library
    void countBook(string bookName);  //!< declaration of count book by given by book name
};
#endif
