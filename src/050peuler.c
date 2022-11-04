/* Sieve prime algorithm */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUMBER 1000000
#define LIMIT 1000000
#define LIMIT_10TH 100000

int main(){

	clock_t start_t, end_t;
	unsigned int a, b;
	char* marked  = calloc(MAX_NUMBER + 2, sizeof(char));
	marked[0] = marked[1] = 1;

	start_t = clock();
	for(a = 2; a < MAX_NUMBER; a++){
		if(marked[a] == 0){
			/*<> Do something with prime </>*/

			for(b = a << 1; b < MAX_NUMBER; b += a)
				marked[b] = 1;
		}
	}

	/* check sum */
	unsigned int ncons, nstart, p, sum, lastPrime;
	for(ncons = 100; ncons < 1000; ncons++){

		nstart = 2;
		while(nstart < LIMIT-ncons){

			sum = 0;
			p = nstart;
			for(a = 0; a < ncons; a++){
				sum += p;
				p++;
				if(p >= LIMIT)
					break;
				while(marked[p] != 0) p++;
			}
			if(sum > LIMIT)
				break;
			if(!marked[sum])
				lastPrime = sum;

			nstart++;
			while(marked[nstart] != 0) nstart++;
		}

	}

	printf(">> sum: %d\n", lastPrime);
	end_t = clock();
	printf("Time taken: %f\n",(double)(end_t - start_t)/CLOCKS_PER_SEC);
	free(marked);
	return 0;
}
