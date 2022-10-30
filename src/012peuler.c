#include <stdio.h>
#include <time.h>
#include <math.h>
#define DIVISORS 500

int getNumOfDivisors(int a){
	int root = sqrt(a);
	int b, divisors = 2;

	if(a & 1){
		for(b = 3; b <= root; b+=2)
			if(b == root)
				divisors++;
			if(a % b == 0)
				divisors +=2;
	}
	else {
		for(b = 2; b <= root; b++)
			if(b == root)
				divisors++;
			else if(a % b == 0)
				divisors +=2;

	}
	return divisors;
}

int main(){

	clock_t start, end;
	start = clock();

	int a = 0, add = 1;
	while(1){
		if(getNumOfDivisors(a) > DIVISORS)
			break;

		a += add;
		add++;
	}
	end = clock();

	printf("First trianglenumber with over %d divisors: %d\n", DIVISORS, a);
	printf("Time taken: %f seconds\n", (double)(end - start)/CLOCKS_PER_SEC);
	return 0;
}
