#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <time.h>
#include <unistd.h>

int main(){

	int i;
	uint64_t sumOfEven = 0, fib = 1, a = 1, b = 1;

	for(i = 0; fib <= 4000000 ; i++){
		if(!(fib & 1))
			sumOfEven += fib;

		fib = a + b;
		a = b;
		b = fib;
	}
	printf("Sum of even fibonaccinumbers: %"PRIu64"\n", sumOfEven);
	return 0;

}