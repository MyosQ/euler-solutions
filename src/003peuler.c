/* Sieve prime algorithm */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define LARGESTPFOF 600851475143
#define MAX_NUMBER sqrt(LARGESTPFOF)


int main(){

	clock_t start_t, end_t;
	uint64_t a, b, largestPf = 0;
	char* marked  = calloc(MAX_NUMBER + 2, sizeof(char));
	marked[0] = marked[1] = 1;
	uint64_t factor;

	start_t = clock();
	for(a = 2; a <= MAX_NUMBER; a++){
		if(marked[a] == 0){
			/*<> Do something with prime </>*/

			factor = LARGESTPFOF /  a;
			if((factor * a) == LARGESTPFOF)
				largestPf = a;

			/* ---------------------------- */
			for(b = a << 1; b <= MAX_NUMBER; b += a)
				marked[b] = 1;
		}
	}
	printf("%"PRIu64"\n", largestPf);
	end_t = clock();

	printf("Time taken: %f\n",(double)(end_t - start_t)/CLOCKS_PER_SEC);
	free(marked);
	return 0;
}
