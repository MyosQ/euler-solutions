#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
int main(){
	FILE* fd;
	int a, b, row = 0, col = 0, array[21][21], prod = 1, maxProd = 0;
	clock_t start, end;

	/* Open file */
	if((fd = fopen("../input_files/011peuler.txt", "r")) == NULL){
		perror("Couldn't open file");
		exit(EXIT_FAILURE);
	}

	/* Read into array */
	while(fscanf(fd, "%d", &a) > 0){

		array[row][col] = a;
		col++;

		if((b = getc(fd)) == '\n'){
			row++;
			col = 0;
		}
	}

	start = clock();
	/* Vertically */
	for(a = 0; a < 16; a++){
		for(b = 0; b < 20; b++){
			prod = array[a][b] * array[a+1][b] * array[a+2][b] * array[a+3][b];
			if(prod > maxProd)
				maxProd = prod;
		}
	}
	/* Horizontally */
	for(a = 0; a < 20; a++){
		for(b = 0; b < 16; b++){
			prod = array[a][b] * array[a][b+1] * array[a][b+2] * array[a][b+3];
			if(prod > maxProd)
				maxProd = prod;
		}
	}
	/* Diagonally, down right */
	for(a = 0; a < 16; a++){
		for(b = 0; b < 16; b++){
			prod = array[a][b] * array[a+1][b+1] * array[a+2][b+2] * array[a+3][b+3];
			if(prod > maxProd)
				maxProd = prod;
		}
	}
	/* Diagonally, down left */
	for(a = 3; a < 20; a++){
		for(b = 0; b < 16; b++){
			prod = array[a][b] * array[a-1][b+1] * array[a-2][b+2] * array[a-3][b+3];
			if(prod > maxProd)
				maxProd = prod;
		}
	}
	end = clock();

	printf("Maxprod: %d\n", maxProd);
	printf("Time taken: %f seconds\n", (double)(end - start)/CLOCKS_PER_SEC);
	return 0;
}
