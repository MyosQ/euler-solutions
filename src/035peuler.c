/* Sieve prime algorithm */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#define MAX_NUMBER 10000000
#define MAXCIRC 1000000

int check_circ(int num, char* marked){
	char numstr[10];
	unsigned int numLen = sprintf(numstr, "%d", num);
	int numInt, power, index, k, i = 0;
	char temp;

	while(i < numLen - 1){

		/* Circulate */
		temp = numstr[0];
		k = 0;
		while(k < numLen - 1){
			numstr[k] = numstr[k + 1];
			k++;
		}
		numstr[k] = temp;


		/* translate to int */
		index = numLen - 1;
		numInt = 0;
		power = 0;
		while(index >= 0){
			numInt += ((numstr[index] - 48) * pow(10, power));
			power++;
			index--;
		}

		if(marked[numInt] != 0)
			return -1;

		i++;
	}

	return 0;
}

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


	int count = 0;
	for(a = 2; a <= MAXCIRC; a++){
		if(marked[a] == 0){
			if(a < 10){
				count ++;
				printf("%d\n", a);
			}

			else if(check_circ(a, marked) == 0){
				count ++;
//				printf("%d circular!!\n", a);
			}
		}
	}


	end_t = clock();
	printf("Total: %d\n", count);
	printf("Time taken: %f\n",(double)(end_t - start_t)/CLOCKS_PER_SEC);
	free(marked);
	return 0;
}
