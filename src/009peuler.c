#include <stdio.h>
#include <math.h>

/*Horrible solution*/

int main(){
	int a,b,c;

	for(a = 100; a < 300; a++)
		for(b = a; b < 400; b++)
			for(c = b; c < 500 ; c++)
				if(pow(a, 2) + pow(b, 2) == pow(c, 2))
					if(a+b+c == 1000){
						printf("%d^2 + %d^2 = %d^2\n", a,b,c);
						printf("prod a*b*c = %d\n", a*b*c);
					}

	return 0;
}
