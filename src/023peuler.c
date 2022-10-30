#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <time.h>
#define MAX 29000

void add_multiples(int a, char *abu){
	int add = a;
	while(a <= MAX){
		abu[a] = 1;
		a += add;
	}
}
int main(){


	clock_t start, end;
	start = clock();
	char *abu = calloc(MAX+1, sizeof(char));
	char *abusum = calloc(MAX+1, sizeof(char));
	unsigned int a, b, bmax, sum;
	uint64_t totalsum = 0;

	for(a = 1; a <= MAX; a++){
		if(abu[a] == 1)
			continue;

		sum = 1;

		bmax = sqrt(a);
		for(b = 2; b <= bmax; b++){
			if(!(a % b)){
				if(b == a/b){
					sum += b;
				}
				else{
					sum += b;
					sum += a/b;
				}
			}
		}
		if(sum > a){
			abu[a] = 1;
			add_multiples(a, abu);
		}
	}

	/* sum of two abundants */
	for(a = 1; a <= MAX/2; a++){
		if(abu[a]){
			for(b = a; b <= MAX; b++){
				if(abu[b]){
					if(a + b <= MAX){
						abusum[a+b] = 1;
					}
				}
			}
		}
	}

	for(a = 1; a <= MAX; a++){
		if(!abusum[a]){
			totalsum += a;
		}
	}


	end = clock();
	printf("sum: %"PRIu64"\n", totalsum);
	printf("Time taken: %f\n", ((double)end-(double)start)/CLOCKS_PER_SEC);
	return 0;
}
