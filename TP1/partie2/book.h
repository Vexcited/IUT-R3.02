#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class Book {
  private:
    string title;
    string author;
    int year;
    int pages;

  public:
    Book();
    string getTitle();
    string getAuthor();
    int getYear();
    int getPages();
    void setTitle(string title);
    void setAuthor(string author);
    void setYear(int year);
    void setPages(int pages);
    void show();
};

Book createBook();

#endif // BOOK_H
