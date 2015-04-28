#include <FPT.h>

double factorial (double n)

{
  int f ;
  f=n ;
  if (n==0){
    return 1 ;
  }
  while (n > 1){
    n=n-1 ;
    f=f*n ;
  }
  return f ;
}

double power (double x, double y)

{
  double a, b ;
  a=1 ;
  b=0 ;
  while (b<fabs(y)){
    a=a*x ;
    b=b+1 ;
  }if ((x==0)&&(y==0)){
    return 1 ;
  }else if (y < 0){
    return 1/a ;
  }else{
    return a ;
  }
}

double bindist (double g, double q, double n)

{
  double probsum ;
  probsum=0 ;
  while (q <= g){
  probsum=probsum + (factorial(g)/(factorial(g-q)*factorial(q)))*(power(n, q)*power(1-n, g-q)) ;
  q++ ;
  }
  return probsum ;
}

int main()

{
  double reds, whites, marbles, grabs, numreds, probabilityred, sum ;
  cout << "How many red marbles do you have?: " ;
  cin >> reds ;
  cout << "\n" << "How many white marbles do you have?: " ;
  cin >> whites ;
  cout << "\n" << "How many grabs will you make?: " ;
  cin >> grabs ;
  cout << "\n" << "How many reds do we want to get?: " ;
  cin >> numreds ;
  marbles=reds+whites ;
  probabilityred=reds/marbles ;
  sum=bindist(grabs, numreds, probabilityred) ;
  cout << sum << endl ;

}
