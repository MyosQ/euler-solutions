#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main(){

	int a, rest, count,maxcount = 0, index = 0;
	char* formerRest = calloc(MAX, sizeof(char));

	for(a = 2; a < MAX; a++){
//		printf("1/%d = 0.", a);
		rest = 1;

		count = 1;
		memset(formerRest, 0, MAX);
		formerRest[1] = 1;

		/* keep on dividing */
		while(1){
//			printf("%d", (rest*10) / a);

			rest = (rest * 10) % a;

			if(formerRest[rest] == 1){
//				printf("() %d digits repeating\n", count);
				break;
			}
			if(rest == 0){
//				printf("\n");
				break;
			}

			formerRest[rest] = 1;
			count ++;
		}

		if(count > maxcount){
			maxcount = count;
			index = a;
		}
	}

	printf("\nd: %d\n", index);

	return 0;
}
