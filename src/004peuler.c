#include <stdio.h>
#include <string.h>


int is_palindrome(char * num){
	int a = 0;
	int len = strlen(num);
	int halflen = len/2;

	while(a < halflen){
		if(num[a] != num[len - 1 -a])
			return 0;

		a++;
	}

	return 1;
}

int main(){
	int a, b;
	char num[10];
	int largestPaProd = 0;
	int prod;

	for(a = 70; a < 1000 ; a++){
		for(b = 70; b < 1000; b++){

			prod = a * b;
			sprintf(num, "%d", prod);
			if(is_palindrome(num))
				if(prod > largestPaProd)
					largestPaProd = prod;
		}
	}
	printf("Largest palindrome: %d\n", largestPaProd);
	return 0;
}
