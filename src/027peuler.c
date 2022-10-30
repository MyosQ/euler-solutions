#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUMBER 20000000

int numberOfPrimes(int a, int b, char* marked){
	int n = 0, num;


	while(n < 1000){
		num = n*n + a*n + b;
		if(num < 1 || marked[num] != 0)
			break;

		n++;
	}
	return n;
}

int main(){
	int a, b, prod;
	unsigned int max = 0, n;
	clock_t start_t, end_t;
	char* marked  = calloc(MAX_NUMBER + 2, sizeof(char));
	marked[0] = marked[1] = 1;

	/* Prime sieve */
	start_t = clock();
	for(a = 2; a < MAX_NUMBER; a++){
		if(marked[a] == 0){
			/*<> Do something with prime </>*/

			for(b = a << 1; b < MAX_NUMBER; b += a)
				marked[b] = 1;
		}
	}
	/*-------------*/

	for(a = -999; a <= 999; a++){
		for(b = -1000; b <= 1000; b++){

			if((n = numberOfPrimes(a, b, marked)) > max){
				max = n;
				prod = a * b;
			}
		}
	}

	end_t = clock();
	printf("Prod = %d\n",prod);
	printf("Time taken: %f\n",(double)(end_t - start_t)/CLOCKS_PER_SEC);
	free(marked);
	return 0;
}
