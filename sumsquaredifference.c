#include <FPT.h>

int sumsquare(int n) {
  int i, sum, result;
  sum = 0;
  while (n > 0) {
    sum += n;
    n--;
  }

  result = pow(sum, 2);
  return result;
}

int squaresum(int n) {
  int i, sum;
  sum = 0;
  while (n > 0) {
    sum += pow(n, 2);
    n--;
  }

  return sum;
}

int main() {
  int number = 100;
  int a, b, difference;
  a = sumsquare(number);
  b = squaresum(number);
  difference = a - b;
  cout << difference << endl;
}
