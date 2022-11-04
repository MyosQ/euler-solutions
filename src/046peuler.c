#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUMBER 1000000
#define MAXCHECK 10000

int goldbachCon(int num, char* marked){

	int i = 3;
	int temp;
	while(i < num){
		temp = num;
		temp -= i;
		temp = temp >> 1;
		if(marked[temp] == 2){
//			printf("%d = %d + 2x%d", num, i, temp);
			return 0;
		}

		/* i = next prime */
		i++;
		while(marked[i] != 0) i++;
	}

	return -1;
}

int main(){

	clock_t start_t, end_t;
	unsigned int a, b, square;
	char* marked  = calloc(MAX_NUMBER + 2, sizeof(char));
	marked[0] = 1;
	marked[1] = 2;/*square*/

	start_t = clock();
	for(a = 2; a < MAX_NUMBER; a++){
		if(marked[a] == 0){
			/*<> Do something with prime </>*/

			for(b = a << 1; b < MAX_NUMBER; b += a)
				marked[b] = 1;

		}
		/* Mark square with 2 */
		if((square = a * a) < MAX_NUMBER)
			marked[square] = 2;

	}


	for(a = 2; a < MAXCHECK; a++)
		if((marked[a] != 0) && (a & 1)){
			if(goldbachCon(a, marked) == 0)
//				printf(" True for %d\n", a);
				continue;
			else{
//				printf("NOT TRUE FOR %d!", a);
				break;
			}
		}

	end_t = clock();
	printf("Answer: Smallest number to falsify goldbachs other conjecture: %d\n", a);
	printf("Time taken: %f\n",(double)(end_t - start_t)/CLOCKS_PER_SEC);
	free(marked);
	return 0;
}
