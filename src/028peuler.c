#include <stdio.h>

int main(){
	int a, sum = 1, add = 0, num = 1;

	while(num < 1002001){

		add += 2;
		for(a = 0; a < 4; a++){
			num += add;
			sum += num;
		}
	}
	printf("Sum: %d\n", sum);

	return 0;
}
