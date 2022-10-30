/* Sieve prime algorithm */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <inttypes.h>
#define MAX_NUMBER 2000000

int main(){

	clock_t start_t, end_t;
	int a, b;
	uint64_t totalSum = 0;
	char* marked  = calloc(MAX_NUMBER + 2, sizeof(char));
	marked[0] = marked[1] = 1;

	start_t = clock();
	for(a = 2; a < MAX_NUMBER; a++){
		if(marked[a] == 0){
			totalSum += a;
			for(b = a << 1; b < MAX_NUMBER; b += a)
				marked[b] = 1;
		}
	}
	end_t = clock();

	printf("total sum of primes below %d: %"PRIu64"\n",MAX_NUMBER, totalSum);
/*	for(a = 0; a < MAX_NUMBER; a++)
		if(marked[a] == 0){
			printf("%dth: %d\n", count, a);
			count++;
		}
*/
	printf("Time taken: %f\n",(double)(end_t - start_t)/CLOCKS_PER_SEC);
	free(marked);
	return 0;
}
