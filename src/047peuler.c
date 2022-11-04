#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define MAX_PRIME 200000
#define KEY_NUMBER 4

int main(){

	clock_t start_t, end_t;
	int a, b, factorCount = 0, consecNumber = 0, maxFact;
	char* marked  = calloc(MAX_PRIME + 2, sizeof(char));
	marked[0] = marked[1] = 1;

	start_t = clock();
	for(a = 2; a < MAX_PRIME; a++){
		if(marked[a] == 0)
			for(b = a << 1; b < MAX_PRIME; b += a)
				marked[b] = 1;
	}


	int lim = MAX_PRIME << 1;
	for(a = 4; a < lim; a++){
		if(marked[a]){	// is not prime
			b = 2;	// first prime
			maxFact = a >> 1;
			while(b <= maxFact){
				if((a % b) == 0){
					factorCount++;
				}
				b++;
				while(marked[b])b++;	//goto next prime
			}
		}
		if(factorCount == KEY_NUMBER){
			consecNumber ++;
			if(consecNumber == KEY_NUMBER)
				break;

		}
		else consecNumber = 0;

		factorCount = 0;
	}




	if(a > MAX_PRIME)
		printf("\nMaxprime not big enough\n");
	else{
		printf("\nFirst %d consecutive numbers with %d distinct prime factors:\n", KEY_NUMBER, KEY_NUMBER);
		printf("%d, %d, %d amd %d\n",a - 3, a - 2, a - 1, a);
	}
	end_t = clock();
	printf("Time taken: %f\n",(double)(end_t - start_t)/CLOCKS_PER_SEC);
	free(marked);
	return 0;
}
