#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX_NUMBER 1000000000

int main(){

	clock_t start_t, end_t;
	unsigned int a, b, inc, sum, primeCount = 0, elseCount = 1;/*for 1*/
	char* marked;
	if((marked = calloc(MAX_NUMBER + 2, sizeof(char))) == NULL){
		printf("Couldnt allocate\n");
		exit(1);
	}
	marked[0] = marked[1] = 1;

	start_t = clock();
	for(a = 2; a < MAX_NUMBER; a++){
		if(marked[a] == 0){
			/*<> Do something with prime </>*/

			for(b = a << 1; b < MAX_NUMBER; b += a)
				marked[b] = 1;
		}
	}

	a = 1;
	inc = 2;
	while(1){
		for(b = 0; b < 4; b++){
			a += inc;
			//printf("%d ", a);
			if(marked[a] == 0)
				primeCount++;
			else
				elseCount++;
		}
		inc += 2;

		sum = (primeCount+elseCount);
		printf("primes: %d   ", primeCount);
		printf("sum: %d\n", sum);

		if(10*primeCount < sum){
			printf("%d  \n", a);
			printf("%d  \n", (int)sqrt(a));
			break;
		}
	}


	//printf("%d/%d = %f\n", primeCount, sum, (double)primeCount/(double)sum);


	end_t = clock();
	printf("Time taken: %f\n",(double)(end_t - start_t)/CLOCKS_PER_SEC);
	free(marked);
	return 0;
}
