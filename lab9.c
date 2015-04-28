#include <FPT.h>

int main()

{
	double size,birthon[365],count,probability,collision ;
	int i,k,b ;
	cout << "Please enter the size of the class: " ;
	cin >> size ;
	i=0 ;
	count=0 ;
	while (i<=1000000){
		k=0 ;
		while (k<365){
			birthon[k]=0 ;
			k++ ;
		}
	   	k=0 ;
		while (k<size){
			b=floor(drand48()*365) ;
			birthon[b]=birthon[b]+1 ;
			k++ ;
		}
	    k=0 ;
		collision=0 ;
		while (k<365){
			if (birthon[k]>1){
				collision=1 ;
			}
			k++ ;
		}
		if (collision==1){
		  count=count+1 ;
		}
		i++ ;
	}
	probability=(count/1000000)*100 ;
	cout << "The probability of a collision is: " << probability << "%" << "\n" ;
}
