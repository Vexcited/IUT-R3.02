#include "somme_r.h"

int somme_r (int n) {
  if (n == 1) {
    return 1;
  }
  else {
    return n + somme_r(n - 1);
  }
}
