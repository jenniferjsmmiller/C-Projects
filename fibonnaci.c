#include <FPT.h>

int main() {
  int num_one, num_two, sum_num, total_sum;
  num_one = 0;
  num_two = 1;
  total_sum = 0;

  //while the second number hasn't hit the limit, 
  //add num_one and num_two together to get the next fibonnaci number
  //set num_one to num_two and num_two to the sum of the numbers and add to get next fibonnaci number
  do {
       sum_num = num_one + num_two;
       num_one = num_two;
       num_two = sum_num;
       if (num_two % 2 == 0)
         total_sum += num_two;
      } while (num_two <= 4000000);
   cout << total_sum << "\n";
}

