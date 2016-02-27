#include <FPT.h>

int palindrome(int number) {
  int reversed = 0;
  int original = number;
  if (number < 10) {
    return 1;
  }

  if (number % 10 == 0) {
    return 0;
  }

  while (number >= 1) {
    reversed = (reversed * 10) + (number % 10);
    number /= 10;
  }

  if (original == reversed) {
    return 1;
  }
  else {
    return 0;
  }
}

int main() {
  int a, b, c, product;
  int number = 0;
  c = 1000;

  while (c > 0) {
    a = 999;
    while (a > 99) {
      b = 999;
      while (b >= a) {
        product = a * b;
        if ((product > number) && (palindrome(product) == 1)) {
          number = product;
        }
        b--;
      }
      a--;
    }
    c--;
  }
  cout << number << endl;
}



