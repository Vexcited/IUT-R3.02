#include <iostream>
#include "book.h"

using namespace std;

Book::Book() {
  title = "";
  author = "";
  year = 0;
  pages = 0;
}

string Book::getTitle() {
  return title;
}

string Book::getAuthor() {
  return author;
}

int Book::getYear() {
  return year;
}

int Book::getPages() {
  return pages;
}

void Book::setTitle(string title) {
  this->title = title;
}

void Book::setAuthor(string author) {
  this->author = author;
}

void Book::setYear(int year) {
  this->year = year;
}

void Book::setPages(int pages) {
  this->pages = pages;
}

void Book::show() {
  cout << this->title << " de " << this->author << endl;
  cout << "Parut en " << this->year << " et contient " << this->pages << " pages." << endl;
}

Book createBook() {
  Book book;

  string title;
  string author;
  int year;
  int pages;

  cout << "Titre : ";
  getline(cin >> ws, title);

  cout << "Auteur : ";
  getline(cin >> ws, author);

  cout << "Année : ";
  cin >> year;

  cout << "Nombre de pages : ";
  cin >> pages;

  book.setTitle(title);
  book.setAuthor(author);
  book.setYear(year);
  book.setPages(pages);

  return book;
}
