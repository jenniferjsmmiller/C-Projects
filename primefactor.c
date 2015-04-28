#include <FPT.h>

int prime (long int n)

{
  while (n%2==0){
    n=n/2 ;
    if (n==2){
      return 2 ;
    }
   }
  for (int i=3 ; i<sqrt(n) ; i=i+2){
    while (n%i==0){
      n=n/i ;
    }
  }
  return n;
}

int main()

{
  long int number = 315 ;
  cout << prime(number) ;
  return 0 ;
}
