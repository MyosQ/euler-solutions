#include <stdio.h>
#include <time.h>
#include <stdint.h>
#define LIMIT 1000000

int main(){
	int a, count, maxCount = 0, maxNum;
	uint64_t n;
	clock_t start, end;
	start = clock();
	for(a = LIMIT / 2; a < LIMIT; a++){
		n = a;
		count = 1;
		while (n > 1){
			if(n & 1){
				n = ((n << 1) + n + 1) >> 1;
				count +=2;
			}
			else{
				n = n >> 1;
				count++;
			}
		}
		if(count > maxCount){
			maxCount = count;
			maxNum = a;
		}
	}
	end = clock();
	printf("MaxChain: %d steps for n < %d. Startnumber: %d\n", maxCount,LIMIT, maxNum);
	printf("Time taken: %f seconds\n", (double)(end - start)/ CLOCKS_PER_SEC);
	return 0;
}
