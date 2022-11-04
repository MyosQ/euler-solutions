#include <stdio.h>

int main(){

	unsigned int p, a, b, c, count = 0, maxcount = 0;

	/* Only need to check even perimeters */
	for(p = 20; p <= 1000; p += 2){
		for(a = p >> 2; a <= p; a++){
			for(b = 1; b <= a; b++){
				if((c = p - (a+b)) < 0)
					break;

				if(a*a + b*b == c*c)
					count++;

			}
		}

		if(count > maxcount){
			maxcount = count;
			printf("p = %d  Count: %d\n", p, count);

		}
		count = 0;
	}
	return 0;
}
