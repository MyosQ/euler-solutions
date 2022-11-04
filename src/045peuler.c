/* Really bad... */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARR_SIZE 500000
#define MAX_N 500000

int main(){
	unsigned int* arrpen;
	unsigned int n, q, twohex, temp, hex, uplim;

	if((arrpen = calloc(ARR_SIZE, sizeof(int))) == NULL){
		fprintf(stderr, "ERROR ALLOC\n");
		exit(-1);
	}

	/* middle */
	for(n = 1; n < MAX_N; n++){
		arrpen[n] = (n*(3*n - 1)) >> 1;
	}

	for(n = 1; n < MAX_N; n++){

		twohex = n*(2*n - 1) << 1;
		temp = sqrt(twohex);
		hex = twohex >> 1;
		if(temp * (temp + 1) == twohex){
			uplim = (n << 1) - (n >> 1);
			for(q = n; q < uplim; q++){
				if(arrpen[q] == hex)
					printf("%d\n", arrpen[q]);
			}
		}
	}
	free(arrpen);

	return 0;
}
