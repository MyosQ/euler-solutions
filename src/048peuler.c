#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define TEN_DIGITS 10000000000
#define MAX 1000
int main(){

	int a, b;
	uint64_t temp = 1, sum = 0;
	for(a = 1; a < MAX; a++){
		temp = 1;
		for(b = 0; b < a; b++){
			temp *= a;
			temp %= TEN_DIGITS;
		}
		sum += temp;
		sum %= TEN_DIGITS;

	}
	printf("Last ten of sum: %"PRId64"\n", sum);
	return 0;
}
