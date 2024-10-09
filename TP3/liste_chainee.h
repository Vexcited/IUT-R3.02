#ifndef LISTE_CHAINEE_H
#define LISTE_CHAINEE_H

#include "noeud.h"

class ListeChainee {
private:
  Noeud* tete;
  Noeud* queue;

public:
  ListeChainee();
  ~ListeChainee();

  void adjtete(int valeur);
  void suptete();
  void adjqueue(int valeur);
  void supqueue();
  int longueur() const;
  int element(int position) const;
  void adjpos(int valeur, int position);
  void suppos(int position);
  void vide();
  bool est_vide() const;
  void affiche();
};

#endif // LISTE_CHAINEE_H
