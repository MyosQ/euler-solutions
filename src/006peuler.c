#include <stdio.h>
#include <math.h>

int main(){
	int a, sumsq=0, sqsum=0;

	for(a = 1; a <= 100; a++)
		sumsq += pow(a, 2);

	for(a = 1; a <= 100; a++)
		sqsum += a;
	sqsum = pow(sqsum, 2);

	printf("sumsq = %d\n", sumsq);
	printf("sqsum = %d\n", sqsum);
	printf("sqsumguess = %d\n", (int)pow(5050, 2));

	printf("diff = %d\n", sqsum - sumsq);
	return 0;
}
