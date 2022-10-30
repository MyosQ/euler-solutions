#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX_NUMBER 20000
#define ABMAX 100

int main(){
	char *twos, *threes;
	twos = calloc(600, sizeof(char));
	threes = calloc(400, sizeof(char));
	int i, j, count = 0;

	/* twos max: 2^6*/
	for(i = 1; i <= 6; i++){
		for(j = i*2; j <= 100*i; j += i){
			twos[j] = 1;
		}
	}
	/* threes max: 3^4*/
	for(i = 1; i <= 4; i++){
		for(j = i*2; j <= 100*i; j += i){
			threes[j] = 1;
		}
	}

	for(i = 0; i <= 600; i++)
		if(twos[i] == 1)
			count ++;

 	for(i = 0; i <= 400; i++)
		if(threes[i] == 1)
			count ++;

	//Squares 25 36 49 100
	count += 50*4;

	//Rows left: 99 - (6two + 4three + 4sq) = 85
	count += 85*99;

	printf("Count: %d\n", count);
	return 0;
}
