#include <stdio.h>
#include <stdlib.h>
#define TRI_SIZE 100+1

int main(){
	int a, row = 1, col = 0, count = 0;

	/* Allocate memory */
	int** arr = calloc(TRI_SIZE, sizeof(int*));
	for(a = 0; a < TRI_SIZE; a++)
		arr[a] = calloc(a + 2, sizeof(int));

	/* Put pascal's triangle */
	arr[0][0] = 1; //Root
	while(row < TRI_SIZE){
		if(col == 0)
			arr[row][col] = 1;
		else{
			arr[row][col] = arr[row - 1][col - 1] + arr[row - 1][col];
			if(arr[row][col] > 1000000)
				arr[row][col] = 1000000;
		}
		col++;
		if(col > row){
			col = 0;
			row ++;
		}
	}

	/* Get values gt 1,000,000 */
	row = 0, col = 0;
	while(row < TRI_SIZE){
		if(arr[row][col] >= 1000000)
			count++;

		col++;
		if(col > row){
			col = 0;
			row ++;
		}

	}

	printf("Number of values over 1,000,000: %d\n", count);

	/* Freeing */
	for(a = 0; a < TRI_SIZE; a++)
		free(arr[a]);
	free(arr);
	return 0;
}
