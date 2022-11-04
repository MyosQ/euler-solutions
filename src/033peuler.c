#include <stdio.h>

int digitCancel(int* at, int* bt){
	int a = *at, b = *bt;
	char num1[2], num2[2];

	sprintf(num1, "%d", a);
	sprintf(num2, "%d", b);

	if(num1[0] == num2[0] && num1[0] != '0'){
		*at = num1[1] - 48;
		*bt = num2[1] - 48;
	}
	else if(num1[1] == num2[0] && num1[1] != '0'){
		*at = num1[0] - 48;
		*bt = num2[1] - 48;
	}
	else if(num1[0] == num2[1] && num1[0] != '0'){
		*at = num1[1] - 48;
		*bt = num2[0] - 48;
	}
	else if(num1[1] == num2[1] && num1[1] != '0'){
		*at = num1[0] - 48;
		*bt = num2[0] - 48;
	}
	else{
		return -1;
	}

	return 0;
}

int main(){
	int a, b, at, bt;
	//a / b

	for(a = 11; a < 100; a++){
		for(b = 10; b < a; b++){
			at = a;
			bt = b;
			if(digitCancel(&at, &bt) < 0)
				continue;

			if(at != 0 && (double)b / (double)a == (double)bt/(double)at)
				printf("%d/%d = %d/%d\n", b, a, bt, at);

		}
	}
	return 0;
}
