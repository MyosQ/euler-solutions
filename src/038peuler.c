#include <stdio.h>
#include <string.h>

int isPan(char num[]){
	int q = 0;
	int used = 0;

	if(strlen(num) != 9)
		return -1;

	while(q < 9){
		if(used & (1 << (num[q]-48)) || num[q] == 48){
			return -1;
		}

		used |= (1 << (num[q] - 48));
		q++;
	}

	return 0;
}
int main(){

	int a;
	char num[30];

	for(a = 2; a < 10000; a++){

			sprintf(num, "%d%d%d%d%d%d", a*1, a*2, a*3, a*4, a*5, a*6);
			if(isPan(num) == 0)
				printf("%d, %s\n", a, num);

			sprintf(num, "%d%d%d%d%d", a*1, a*2, a*3, a*4, a*5);
			if(isPan(num) == 0)
				printf("%d, %s\n", a, num);

			sprintf(num, "%d%d%d%d", a*1, a*2, a*3, a*4);
			if(isPan(num) == 0)
				printf("%d, %s\n", a, num);

			sprintf(num, "%d%d%d", a*1, a*2, a*3);
			if(isPan(num) == 0)
				printf("%d, %s\n", a, num);

			sprintf(num, "%d%d", a*1, a*2);
			if(isPan(num) == 0)
				printf("%d, %s\n", a, num);

	}
	return 0;
}
