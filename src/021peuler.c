#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

int main(){

	unsigned int *darr = calloc(MAX, sizeof(int));
	unsigned int a, b, bmax, sum, amisum = 0;
	char addOdd;

	for(a = 1; a <= MAX; a++){
		sum = 1;
		addOdd = 2;

		if(!(a & 1)){
			addOdd = 1;
			sum += 2;
		}

		bmax = a >> 1;
		for(b = 3; b <= bmax; b += addOdd)
			if(a % b == 0)
				sum += b;

		darr[a] = sum;
	}

	for(a = 1; a <= MAX; a++){
		if(darr[a] != a && darr[a] <= MAX && darr[darr[a]] == a){
			printf("Pair: %d   %d\n", a, darr[a]);
			amisum += a;
		}
	}
	printf("amisum: %d\n", amisum);

	return 0;
}
