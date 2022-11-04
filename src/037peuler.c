#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX_NUMBER 20000000

int myPow(int a, int b){
	int i, prod = 1;
	for(i = 0; i < b; i++)
		prod *= a;

	return prod;
}
int main(){
	clock_t start_t, end_t;
	unsigned int a, b, temp, nDigits, sum = 0;
	char* marked  = calloc(MAX_NUMBER + 2, sizeof(char));
	char isTrunc;
	marked[0] = marked[1] = 1;

	start_t = clock();
	for(a = 2; a < MAX_NUMBER; a++){
		if(marked[a] == 0){
			/*<> Do something with prime </>*/

			for(b = a << 1; b < MAX_NUMBER; b += a)
				marked[b] = 1;
		}
	}

	for(a = 11; a < 5000000; a += 2){
		if(marked[a] == 0){
			isTrunc = 1;

			/* left to right */
			temp = a;
			nDigits = floor(log10(temp)) + 1;

			while(temp > 9){
				temp -= (temp/myPow(10, nDigits-1))*myPow(10, nDigits-1);
				if(marked[temp] != 0){
					isTrunc = 0;
					break;
				}
				nDigits --;
			}

			/* right to left */
			temp = a;
			temp /= 10;
			while(temp > 0){
				if(marked[temp] != 0){
					isTrunc = 0;
					break;
				}

				temp /= 10;
			}

			if(isTrunc == 1){
				printf("%d\n", a);
				sum += a;
			}
		}
	}

	end_t = clock();
	printf("Sum: %u\n", sum);
	printf("Time taken: %f\n",(double)(end_t - start_t)/CLOCKS_PER_SEC);
	free(marked);
	return 0;
}

