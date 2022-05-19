/*!including operations header file*/
#include "Books.h"
//!header guard
#ifndef LIBRARYBOOKS_H
#define LIBRARYBOOKS_H
/*!class LibBooks inheriting the class Books*/
class LibBooks: public Books {
public:
  void welcomemsg(); //!< declaration of print welcome message function
  int countBook(); //!< declaration of count total books into the library
};
#endif