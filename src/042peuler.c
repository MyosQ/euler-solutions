#include <stdio.h>
#include <stdlib.h>

int isTri(int sum){

	if(sum == 1 ||
	sum == 3 ||
	sum == 6 ||
	sum == 10 ||
	sum == 15 ||
	sum == 21 ||
	sum == 28 ||
	sum == 36 ||
	sum == 45 ||
	sum == 55 ||
	sum == 66 ||
	sum == 78 ||
	sum == 91 ||
	sum == 105 ||
	sum == 120 ||
	sum == 136 ||
	sum == 153 ||
	sum == 171)
		return 0;

	else
		return -1;
}

int main(){

	int a = 1;
	unsigned int letterSum, count = 0;
	FILE* fp;
	if((fp = fopen("../input_files/042peuler.txt", "r")) == NULL){
		perror("Cant open file");
		exit(1);
	}


	while(a != EOF){
		letterSum = 0;
		while((a = getc(fp)) != '"' && a != EOF);
		while(a != EOF && (a = getc(fp)) != '"'){
			printf("%c", a);
			letterSum += (a - 64);
		}
		printf("   sum: %d\n", letterSum);

		if(isTri(letterSum) == 0)
			count ++;
	}

	printf("\nTri Words: %d\n", count);



	return 0;
}
