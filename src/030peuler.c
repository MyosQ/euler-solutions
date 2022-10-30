#include <stdio.h>
#include <math.h>
int main(){
	int one, two, three, four, five, six;
	int a, powsum, totalsum = 0;
	for(a = 2; a < 1000000; a++){
		one = a / 100000;
		two = (a - (one*100000))/10000;
		three = (a - (one*100000 + two*10000))/1000;
		four = (a - (one*100000 + two*10000 + three*1000))/100;
		five = (a - (one*100000 + two*10000 + three*1000 + four*100))/10;
		six = (a - (one*100000 + two*10000 + three*1000 + four*100 + five*10));

		powsum = pow(one, 5) + pow(two, 5) + pow(three, 5) + pow(four, 5) + pow(five, 5) + pow(six, 5);
		if(powsum == a){
			printf("%d\n", a);
			totalsum += a;
		}
	}
	printf("\ntotalsum = %d\n", totalsum);
	return 0;
}
