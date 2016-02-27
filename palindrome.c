#include <FPT.h>

int palindrome(int n)

{
  int reversed=0 ;
  int original=n ;
  if (n < 10){
    return 1 ;
  }
  if (n % 10==0){
    return 0 ;
  }
  while (n >= 1){
    reversed=(reversed*10)+(n%10) ;
    n=n/10 ;
  }
  if (original==reversed){
    return 1 ;
  }else{
    return 0 ;
  }
}

int main()

{
  int a, b, c, product ;
  int number=0 ;
  c=1000 ;

  while (c > 0){
    a=999 ;
    while (a > 99){
      b=999 ;
      while (b >= a){
        product=a*b ;
        if ((product > number)&&(palindrome(product)==1)){
          number=product ;
        }
        b=b-1 ;
      }
      a=a-1 ;
    }
    c=c-1 ;
  }
  cout << number << endl ;
}



