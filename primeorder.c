#include <FPT.h>

long int prime(long int n) {
  int x, y, r, w;
  x = 0;
  w = n;

  if (n == 1) {
    return 0;
  }

  while((x == 0) && (n > 2)) {
    n--;
    r = fmod(w, n);
    if(r == 0) {
      x = 1;
    }
  }

  if (x == 1) {
    return 0;
  }
  else {
    return 1;
  }
}

int main() {
  long int number, i;
  int belief, k, newnumber;
  number = 1;
  k = 0;
  i = 1;

  while (i < 1000000) {
    if (prime(i) == 1) {
      k++;
    }
    if (k > 9999 && prime(i) && k < 10010) {
      cout << i << endl;
    }
    i += 2;
  }
}
