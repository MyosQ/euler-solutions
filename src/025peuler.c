#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int addTwo(char* str1, char* str2, char* sum);

int main (){

	char* sum = calloc(1000, sizeof(char));
	char* num1 = calloc(1000, sizeof(char));
	char* num2 = calloc(1000, sizeof(char));
	char* temp;
	num1[0] = '1';
	num2[0] = '1';
	int fibo_index = 2;
	while(strlen(num2) < 1000){
		fibo_index++;
		addTwo(num1, num2, sum);

		temp = num1;
		num1 = num2;
		num2 = sum;
		sum = temp;

	}
	printf("index of first 1000-digit fibo = %d\n", fibo_index);

	free(num1);
	free(num2);
	free(sum);
	exit(0);
}
