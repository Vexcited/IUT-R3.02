#include "noeud.h"

Noeud::Noeud(int val) {
  valeur = val;
  suivant = 0; // équivalent de nullptr
}

Noeud::~Noeud() {}
