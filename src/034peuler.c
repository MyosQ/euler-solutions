#include <stdio.h>

int factorial(int a){
	switch(a){
		case 0:
			return 1;
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 6;
		case 4:
			return 24;
		case 5:
			return 120;
		case 6:
			return 720;
		case 7:
			return 5040;
		case 8:
			return 40320;
		case 9:
			return 362880;
		default:
			return -1;
	}
}
int main(){
	int i, a, facSum, totalsum = 0, strLen;
	char num[10];

	for(i = 3; i < 10000000; i++){
		strLen = sprintf(num, "%d", i);
		a = 0;
		facSum = 0;


		while(a < strLen){
			facSum += factorial(num[a] - 48);
			a++;
		}

		if(facSum == i){
			printf("%d\n", i);
			totalsum += facSum;
		}
	}
	printf("Total sum: %d\n", totalsum);
	return 0;
}
