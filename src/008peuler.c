#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(){
	FILE* fd = fopen("../input_files/008peuler.txt", "r+");
	int a,  count = 0, arrlen;
	char arr[1100];
	int64_t prod, maxprod = 0;

	while((a = getc(fd)) != EOF){
		if(a != '\n'){
			arr[count] = a;
			count ++;
		}
	}
	arrlen = count;
	for(count = 0; count < arrlen - 13; count++){
		prod = 1;
		for(a = 0; a < 13; a++){
			printf("%d ", (arr[count + a] - 48));
			prod *= arr[count + a] - 48;
		}
		printf("  =   %"PRId64" \n", prod);
		if(prod < 0){
			fprintf(stderr,"Buffer overflow.\n");
			exit(0);
		}
		if(prod > maxprod)
			maxprod = prod;
	}
	printf("\nmaxprod = %"PRId64"\n", maxprod);
	fclose(fd);
	return 0;
}
