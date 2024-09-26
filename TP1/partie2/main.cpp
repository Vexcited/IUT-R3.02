#include <iostream>
#include "medias.h"
#include "book.h"

void header (string title) {
  cout << "\n\n" << title << "\n";

  for (int i = 1; i < title.length(); i++) {
    cout << "-";
  }

  cout << "\n" << endl;
}

int selection () {
  header("Bienvenue dans votre bibliothèque !");

  cout << "1. Afficher l'ensemble des livres de la bibliothèque" << endl;
  cout << "2. Ajouter un livre" << endl;
  cout << "3. Supprimer un livre" << endl;
  cout << "4. Rechercher un livre (par le titre)" << endl;
  cout << "5. Quitter" << endl;

  cout << "\nEntrez votre choix : ";

  int selection;
  cin >> selection;

  return selection;
}

int main () {
  Medias medias;
  int choice = 0;

  while ((choice = selection()) != 5) {
    switch (choice) {
      case 1:
        header("Votre bibliothèque de livres");
        medias.showBooks();
        break;
      case 2: {
        header("Procédure d'ajout d'un livre");
        Book book = createBook();
        medias.addBook(book);
        break;
      }
      case 3:
        header("Procédure de suppression d'un livre");
        
        int index;
        cout << "Index du livre à supprimer : ";
        cin >> index;

        medias.removeBook(index);
        break;
      case 4:
        header("Rechercher un livre dans la bibliothèque");

        string title;
        cout << "Titre du livre à rechercher : ";
        getline(cin >> ws, title);

        Book* book = medias.searchBook(title);
        
        if (book != nullptr) {
          book->show();
        }
        else {
          cout << "Le livre n'a pas été trouvé !" << endl;
        }

        break;
    }
  }

  return 0;
}