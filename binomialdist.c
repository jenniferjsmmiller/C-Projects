#include <FPT.h>

//returns factorial of parameter
double factorial(double number) {
  int factorial;
  factorial = number;
  if (number == 0){
    return 1;
  }
  while (number > 1){
    number = number - 1;
    factorial = factorial * number;
  }
  return factorial;
}

//returns result of the power of the number
double power(double number, double power) {
  double power_result, increment;
  power_result = 1;
  increment = 0;

  while (increment < fabs(power)) {
    power_result *= number;
    increment++;
  }

  if ((number == 0) && (power == 0)) {
    return 1;
  }
  else if (power < 0) {
    return 1 / power_result;
  }
  else {
    return power_result;
  }
}

double bindist(double grabs, double num_reds, double probability_red)
{
  double probsum;
  probsum = 0;
  while (num_reds <= grabs){
    probsum += (factorial(grabs) / (factorial(grabs - num_reds) * factorial(num_reds))) 
      * (power(probability_red, num_reds) * power(1 - probability_red, grabs - num_reds)) ;
    num_reds++;
  }
  return probsum;
}

int main()
{
  double reds, whites, marbles, grabs, num_reds, probability_red, sum;
  cout << "How many red marbles do you have?: ";
  cin >> reds;
  cout << "\n" << "How many white marbles do you have?: ";
  cin >> whites;
  cout << "\n" << "How many grabs will you make?: ";
  cin >> grabs;
  cout << "\n" << "How many reds do we want to get?: ";
  cin >> num_reds ;
  marbles = reds + whites;
  probability_red = reds / marbles;
  sum = bindist(grabs, numreds, probability_red) ;
  cout << sum << endl ;
}
