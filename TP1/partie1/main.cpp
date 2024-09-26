#include <iostream>
#include "somme_r.h"

using namespace std;

int main () {
  int n;

  cout << "Entrez un nombre : ";
  cin >> n;

  cout << "La somme des entiers de 1 à " << n << " est " << somme_r(n) << endl;

  return 0;
}
