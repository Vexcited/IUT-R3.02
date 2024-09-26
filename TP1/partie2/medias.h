#ifndef MEDIAS_H
#define MEDIAS_H

#include "book.h"

const int MAX_BOOKS = 100;

class Medias {
  private:
    Book books[MAX_BOOKS];
    int nbBooks;
  public:
    Medias();
    void addBook(const Book& book);
    void removeBook(int index);
    Book* searchBook(string title);
    void showBooks();
};

#endif // MEDIAS_H
