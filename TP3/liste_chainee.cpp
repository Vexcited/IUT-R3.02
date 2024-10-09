#include <iostream>
#include <stdexcept>

#include "liste_chainee.h"
#include "noeud.h"

using namespace std;

ListeChainee::ListeChainee() {
  tete = nullptr;
  queue = nullptr;
}

ListeChainee::~ListeChainee() {
    vide();
}

void ListeChainee::adjtete(int valeur) {
    Noeud* nouveau = new Noeud(valeur);
    if (est_vide()) {
        tete = queue = nouveau;
    } else {
        nouveau->suivant = tete;
        tete = nouveau;
    }
}

void ListeChainee::suptete() {
  if (est_vide()) return;

  Noeud* temp = tete;
  tete = tete->suivant;
  delete temp;

  if (tete == nullptr) {
    queue = nullptr;
  }
}

void ListeChainee::adjqueue(int valeur) {
  Noeud* nouveau = new Noeud(valeur);

  if (est_vide()) {
    tete = queue = nouveau;
  }
  else {
    queue->suivant = nouveau;
    queue = nouveau;
  }
}

void ListeChainee::supqueue() {
  if (est_vide()) return;

  if (tete == queue) {
    delete tete;
    tete = queue = nullptr;
  }
  else {
    Noeud* temp = tete;
    while (temp->suivant != queue) {
      temp = temp->suivant;
    }

    delete queue;
    queue = temp;
    queue->suivant = nullptr;
  }
}

int ListeChainee::longueur() const {
  int count = 0;
  Noeud* temp = tete;
  while (temp != nullptr) {
    count++;
    temp = temp->suivant;
  }

  return count;
}

int ListeChainee::element(int position) const {
  // on renvoie une erreur si la position est invalide
  if (position < 0 || position >= longueur()) {
    throw out_of_range("Position invalide");
  }

  Noeud* temp = tete;
  for (int i = 0; i < position; i++) {
    temp = temp->suivant;
  }

  return temp->valeur;
}

void ListeChainee::adjpos(int valeur, int position) {
  // on renvoie une erreur si la position est invalide
  if (position < 0 || position > longueur()) {
    throw out_of_range("Position invalide");
  }

  if (position == 0) {
    adjtete(valeur);
  }
  else if (position == longueur()) {
    adjqueue(valeur);
  }
  else {
    Noeud* nouveau = new Noeud(valeur);
    Noeud* temp = tete;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->suivant;
    }
    nouveau->suivant = temp->suivant;
    temp->suivant = nouveau;
  }
}

void ListeChainee::suppos(int position) {
  // on renvoie une erreur si la position est invalide
  if (position < 0 || position >= longueur()) {
    throw out_of_range("Position invalide");
  }

  if (position == 0) {
    suptete();
  }
  else {
    Noeud* temp = tete;
    for (int i = 0; i < position - 1; i++) {
      temp = temp->suivant;
    }

    Noeud* to_delete = temp->suivant;
    temp->suivant = to_delete->suivant;

    if (to_delete == queue) {
      queue = temp;
    }

    delete to_delete;
  }
}

void ListeChainee::vide() {
  while (!est_vide()) {
    suptete();
  }
}

bool ListeChainee::est_vide() const {
  return tete == nullptr;
}

void ListeChainee::affiche() {
  Noeud* temp = tete;
  while (temp != nullptr) {
    cout << temp->valeur << " ";
    temp = temp->suivant;
  }

  cout << endl;
}
