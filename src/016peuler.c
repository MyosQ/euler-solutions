#include <stdio.h>
#include <string.h>
#define MAX_EXPO 1000
int addTwo(char* str1, char* str2, char* sum);

int main(){


	int a, len, digitsum = 0;
	char sum[MAX_EXPO], one[] = "1";
	addTwo(one, one, sum);

	for(a = 1; a < MAX_EXPO; a++)
		if(addTwo(sum, sum, sum) < 0)
			return -1;

	len = strlen(sum);
	for(a = 0; a < len; a++)
		digitsum += (sum[a] - 48);

	printf("Digitsum of %s = %d\n", sum, digitsum);

	return 0;
}
