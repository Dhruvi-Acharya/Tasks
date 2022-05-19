/*!including input output stream header file*/
#include <iostream>
using namespace std;
/*!including LibBooks header file*/
#include "../include/LibBooks.h"

void LibBooks::welcomemsg(){ /*!Runtime polymorphism*/ //!< definition of printwelcomeMessage function
  cout<<"\n------------Welcome------------\n";
}

int LibBooks::countBook(){ /*!Runtime polymorphism*/ //!< definition of count the total number of books
    return stock; //!< return stock of the particular book
 }