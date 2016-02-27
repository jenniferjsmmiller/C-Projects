#include <FPT.h>

//program will calculate the probability that any two given people or more in the class will share the same
//birthday based on the class size
int main() {
	double class_size, birthon[365], count, probability, collision;
	int i, k, b;

	cout << "Please enter the size of the class: ";
	cin >> class_size;
	i = 0;
	count = 0;

	//loops a million times for probability accuracy
	while (i <= 1000000) {
		k = 0;
		//initialize birth array to 0
		while (k < 365) {
			birthon[k] = 0;
			k++;
		}

	   	k = 0;
	   	//b generates random day of year that corresponds to index value in birth array
	   	//the value for that date in birth array will be incremented each time it gets hit
	   	//will loop until each person in the class is accounted for
		while (k < class_size) {
			b = floor(drand48() * 365);
			birthon[b] = birthon[b] + 1;
			k++;
		}

	    k = 0;
		collision = 0;
		//cycles through birthon array and if any index value for the array is larger than one,
		//then a collision has occurred
		while (k < 365) {
			if (birthon[k] > 1) {
				collision = 1;
			}
			k++;
		}

		//if collision s true, then increment count by one
		if (collision == 1) {
		  count++;
		}
		i++;
	}
	probability = (count/1000000) * 100;
	cout << "The probability of a collision is: " << probability << "%" << "\n";
}
