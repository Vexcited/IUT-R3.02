#include <iostream>
#include "medias.h"

using namespace std;

Medias::Medias() {
  nbBooks = 0;
}

void Medias::addBook(const Book& book) {
  if (nbBooks < MAX_BOOKS) {
    books[nbBooks] = book;
    nbBooks++;
  }
  else {
    cout << "La bibliothèque est pleine !" << endl;
  }
}

void Medias::removeBook(int index) {
  if (index < 0 || index >= nbBooks) {
    cout << "L'index est invalide !" << endl;
    return;
  }

  for (int i = index; i < nbBooks - 1; i++) {
    books[i] = books[i + 1];
  }

  nbBooks--;
}

Book* Medias::searchBook(string title) {
  for (int i = 0; i < nbBooks; i++) {
    Book& book = books[i];

    if (book.getTitle() == title) {
      return &book;
    }
  }

  return nullptr;
}

void Medias::showBooks() {
  if (nbBooks == 0) {
    cout << "La bibliothèque est vide !" << endl;
    return;
  }

  for (int i = 0; i < nbBooks; i++) {
    cout << "Livre #" << i + 1 << endl;
    books[i].show();

    // On ajoute un séparateur seulement s'il y a plus d'un livre.
    if (nbBooks > 1) {
      cout << endl;
    }
  }
}
