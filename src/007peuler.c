#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX_NUMBER 10000

int main(){
	int a, b, it_index;
	char isPrime;

	/* Save all primes into an array */
	unsigned int* array = calloc(MAX_NUMBER +10, sizeof(unsigned int));
	unsigned int primeCount = 2;
	array[0] = 2;
	array[1] = 3;

	clock_t start_t, end_t;
	start_t = clock();

	for(a = 5; primeCount <= MAX_NUMBER; a+=2){
		isPrime = 1;

		it_index = 2;
		b = array[1];
		while(b <= sqrt(a)){
			if(!(a % b)){
				isPrime = 0;
				break;
			}
			b = array[it_index];
			it_index ++;

		}

		if(isPrime){
			array[primeCount] = a;
			primeCount++;
		}

	}
	end_t = clock();

	printf("%dth prime: %d\n", primeCount, array[primeCount-1]);
	printf("Time taken: %f\n",(double)(end_t - start_t)/CLOCKS_PER_SEC);
	free(array);
	return 0;
}
