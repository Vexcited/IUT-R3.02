#ifndef NOEUD_H
#define NOEUD_H

class Noeud {
public:
  int valeur;
  Noeud* suivant;

  Noeud(int val);
  ~Noeud();
};

#endif // NOEUD_H
