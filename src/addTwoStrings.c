#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int max(int a, int b){
	if(a > b)
		return a;
	else return b;
}
int min(int a, int b){
	if(a < b)
		return a;
	else return b;
}
char* maxString(char* str1, char* str2){
	if(strlen(str1) > strlen(str2))
		return str1;
	else return str2;
}

int addTwo(char* str1, char* str2, char* sum){
	if(str1 == NULL || str2 == NULL)
		return -1;

	int index_1 = strlen(str1) - 1;
	int index_2 = strlen(str2) - 1;
	int maxLength = max(index_1, index_2) + 1;
	int minLength = min(index_1, index_2) + 1;
	int index_max = maxLength - 1;
	int a, res, sumlen, carry = 0;

	char* maxstr = maxString(str1, str2);
	char* sum_i = calloc(maxLength +2, sizeof(char));

	/* adding */
	for(a = 0; a < maxLength ; a++){
		if(a < minLength)
			res = str1[index_1 - a] + str2[index_2 - a] - 96 + carry;
		else
			res = maxstr[index_max - a] - 48 + carry;

		carry = 0;
		if(res > 9){
			carry = 1;
			res -= 10;
		}
		sum_i[a] = res + 48;
	}
	if(carry){
		sum_i[a] = carry + 48;
		sum_i[a + 1] = '\0';
	}
	else
		sum_i[a] = '\0';

	/*Copy to sum and turning right way*/
	sumlen = strlen(sum_i);
	for(a = 0; a < sumlen ; a++){
		sum[a] = sum_i[sumlen - 1 - a];
	}
	sum[a] = '\0';

	free(sum_i);
	return 0;
}
