#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*  Addtwostring not working ?! */
/* Had to calculate sum by hand */
void rec_fill(char palin[], int index, char isTaken[], char sum[]);
void addTwo(char* str1, char* str2, char* sum);

int main(){
	char palin[10], isTaken[10], sum[15];
	memset(palin, 0, 10);
	memset(isTaken, 0, 10);
	memset(sum, 0, 15);
	clock_t start_t, end_t;
	start_t = clock();

	memset(sum, 0, 15);

	rec_fill(palin, 0, isTaken, sum);

	end_t = clock();
	printf("Time taken: %f\n",(double)(end_t - start_t)/CLOCKS_PER_SEC);
	printf("Sum: %s\n", sum);
	return 0;
}

void rec_fill(char palin[], int index, char isTaken[], char sum[]){
	int a;

	if(index == 10){
		/* 1, d4 even */
		if(!((palin[3]-48) & 1) &&
		/* 2, d3d4d5 div by 3*/
		(palin[2]-48+palin[3]-48+palin[4]-48) % 3 == 0 &&
		/* 3, d6 div by 5 */
		(palin[5]-48) % 5 == 0 &&
		/* 4, d5d6d7 div by 7 */
		(100*(palin[4]-48) + 10*(palin[5]-48) + (palin[6]-48)) % 7 == 0 &&
		/* 5, d6d7d8 div by 11 */
		(100*(palin[5]-48) + 10*(palin[6]-48) + (palin[7]-48)) % 11 == 0 &&
		/* 6, d7d8d9 div by 13 */
		(100*(palin[6]-48) + 10*(palin[7]-48) + (palin[8]-48)) % 13 == 0 &&
		/* 7, d8d9d10 div by 17 */
		(100*(palin[7]-48) + 10*(palin[8]-48) + (palin[9]-48)) % 17 == 0
		){

			printf("Palin: %s  ", palin);

			addTwo(palin, sum, sum);
			printf("Sum: %s  \n", sum);
		}
		return;
	}

	/* Fill recursively to get pandigitals */
	for(a = 0; a < 10; a++){
		if(isTaken[a] == 0){
			palin[index] = a + 48;
			isTaken[a] = 1;

			rec_fill(palin, index + 1, isTaken, sum);
			isTaken[a] = 0;
		}
	}
}
