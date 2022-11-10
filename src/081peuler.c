#include <stdio.h>
#include <stdlib.h>

struct cell{
	int val;
	int minPath;
};

int main(){

	struct cell arr[80][80];
	int row, col;
	FILE* fp;

	/* Open file */
	if((fp = fopen("../input_files/081peuler.txt", "r")) == NULL){
		perror("Cant open file");
		exit(1);
	}

	/* Read values */
	for(row = 0; row < 80; row++)
		for(col = 0; col < 80; col++)
			fscanf(fp,"%d,", &(arr[row][col].val));



	for(row = 0; row < 80; row++){
		for(col = 0; col < 80; col++){
			if(row == 0 && col == 0)
				arr[row][col].minPath = arr[row][col].val;

			else if(row == 0)
				arr[row][col].minPath = arr[row][col].val + arr[row][col-1].minPath;

			else if(col == 0)
				arr[row][col].minPath = arr[row][col].val + arr[row-1][col].minPath;

			else{
				arr[row][col].minPath = min(arr[row][col-1].minPath , arr[row-1][col].minPath) + arr[row][col].val;

			}

		}
	}
	printf("minPath: %d\n", arr[79][79].minPath);

	return 0;
}
