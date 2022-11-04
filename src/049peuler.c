
/* Sieve prime algorithm */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUMBER 20000
#define INCREASE 3330

int isPerm(int* num){
	unsigned int n1, n2, n3, startn;
	char arr[10];
	memset(arr, 0, 10);
	arr[num[0]] = 1;
	arr[num[1]] = 1;
	arr[num[2]] = 1;
	arr[num[3]] = 1;

	n1 = num[0]*1000 + num[1]*100 + num[2]*10 + num[3];
	n2 = n1 + 3330;

	startn = n2;
	num[0] = startn/1000;
	num[1] = (startn - (num[0]*1000))/100;
	num[2] = (startn - (num[0]*1000) - (num[1]*100))/10;
	num[3] = (startn - (num[0]*1000) - (num[1]*100) - (num[2]*10));

	if(arr[num[0]] == 0 || arr[num[1]] == 0 || arr[num[2]] == 0 || arr[num[3]] == 0)
		return -1;

	n3 = n2 + 3330;
	startn = n3;
	num[0] = startn/1000;
	num[1] = (startn - (num[0]*1000))/100;
	num[2] = (startn - (num[0]*1000) - (num[1]*100))/10;
	num[3] = (startn - (num[0]*1000) - (num[1]*100) - (num[2]*10));

	if(arr[num[0]] == 0 || arr[num[1]] == 0 || arr[num[2]] == 0 || arr[num[3]] == 0)
		return -1;


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


	unsigned int startn;
	int num[4];
	for(startn = 2; startn < 10000; startn++){

		if(marked[startn] != 0 || marked[startn+3330] != 0 || marked[startn+2*3330] != 0)
			continue;


		num[0] = startn/1000;
		num[1] = (startn - (num[0]*1000))/100;
		num[2] = (startn - (num[0]*1000) - (num[1]*100))/10;
		num[3] = (startn - (num[0]*1000) - (num[1]*100) - (num[2]*10));

		if(isPerm(num) == 0)
			printf("%d %d %d \n", startn, startn +3330, startn+6660);

	}


	end_t = clock();
	printf("Time taken: %f\n",(double)(end_t - start_t)/CLOCKS_PER_SEC);
	free(marked);
	return 0;
}
