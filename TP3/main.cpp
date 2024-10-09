#include <iostream>
#include "liste_chainee.h"

using namespace std;

int main() {
    ListeChainee liste;

    liste.adjtete(3);
    liste.adjtete(2);
    liste.adjtete(1);
    liste.adjqueue(4);
    liste.adjqueue(5);

    cout << "Liste initiale : ";
    liste.affiche();

    cout << "Longueur de la liste : " << liste.longueur() << endl;

    cout << "Élément à la position 2 : " << liste.element(2) << endl;

    liste.adjpos(10, 2);
    cout << "Liste après ajout de 10 à la position 2 : ";
    liste.affiche();

    liste.suppos(3);
    cout << "Liste après suppression de l'élément à la position 3 : ";
    liste.affiche();

    liste.suptete();
    liste.supqueue();
    cout << "Liste après suppression de la tête et de la queue : ";
    liste.affiche();

    cout << "La liste est vide ? " << (liste.est_vide() ? "Oui" : "Non") << endl;

    liste.vide();
    cout << "Liste après vidage : ";
    liste.affiche();

    cout << "La liste est vide ? " << (liste.est_vide() ? "Oui" : "Non") << endl;

    return 0;
}
