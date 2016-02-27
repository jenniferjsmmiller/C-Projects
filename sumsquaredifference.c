#include <FPT.h>

int sumsquare(int n)

{
  int i, sum, res ;
  sum=0 ;
  while (n > 0){
    sum=sum+n ;
    n=n-1 ;
  }
  res=pow(sum, 2) ;
  return res ;
}

int squaresum(int n)

{
  int i, sum, res ;
  sum=0 ;
  while (n > 0){
    sum=sum+pow(n, 2) ;
    n=n-1 ;
  }
  return sum ;
}

int main()

{
  int number=100 ;
  int a, b, difference ;
  a=sumsquare(number) ;
  b=squaresum(number) ;
  difference=a-b ;
  cout << difference << endl ;
}
