#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 9
#define BOXSIZE 3
#define NUMBER_OF_SUDOKUS 50

int ok(char** arr, int row, int col, int k);
int su_solver(char** arr, int row, int col);
void err_sys(char* msg);

int main(){
	FILE* fd;
	int a, i = 0, k = 0, solved, sumofTopThree = 0, sudNum = 0;
	char ** arr;
	clock_t start, end;
	start = clock();

	/* Allocate for 2-d array */
	if ((arr = calloc(10, sizeof(char*))) == NULL)
		err_sys("Allocation error\0");
	for(a = 0; a < 10; a++)
		if((arr[a] = calloc(10, sizeof(char))) == NULL)
			err_sys("Allocation error\0");

	/* Open file */
	if((fd = fopen("../input_files/096peuler.txt", "r")) == NULL)
		err_sys("Can't open file");

	/* The 'main' loop. One SuDoku at a time. */
	while(sudNum < NUMBER_OF_SUDOKUS){
		k = 0;
		i = 0;

		/* Skip first line */
		while((a = getc(fd)) != '\n');

		/* Read into 2-d array */
		while(k < 9 && a != EOF){
			while((a = getc(fd)) != '\n' && a != EOF){
				arr[k][i] = a;
				i++;
			}
			i = 0;
			k++;
		}

		/* Solving part */
		if ((solved = su_solver(arr, 0, 0)) < 0){
			fprintf(stderr, "No solution\n");
			goto FREE;
		}
		sumofTopThree += 100*(arr[0][0] - 48) + 10*(arr[0][1] - 48) + (arr[0][2] - 48);

		printf("Nr %d Solved!\n", sudNum+1);
		sudNum++;
	}
	/*--- End of Su Doku's ---*/

	/* Print result */
	end = clock();
	printf("time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("sum: %d\n", sumofTopThree);

	/* Freeing */
	FREE:
	fclose(fd);
	for(a = 0; a < 10; a++){
		free(arr[a]);
	}
	free(arr);
	return 0;
}

/* The valid-checker.
 Returns 0 if number works, else -1. */
int ok(char** arr, int row, int col, int k){
	int a, b, startRow, startCol;

	/* horizontally */
	for(a = 0; a < SIZE; a++)
		if(arr[row][a] == k+48 && a != col)
			return -1;

	/* Vertically */
	for(a = 0; a < SIZE; a++)
		if(arr[a][col] == k+48 && a != row)
			return -1;

	/* "Boxly" */
	startRow = row / 3 * 3;
	startCol = col / 3 * 3;

	for(a = startRow; a < startRow + BOXSIZE; a++)
		for(b = startCol; b < startCol + BOXSIZE; b++)
			if(arr[a][b] == k+48 && a != row && b != col)
				return -1;
	return 0;
}


/* The sudoku solver.
Returns 0 if puzzle solved, else -1.
If solved it updates arr with it. */
int su_solver(char** arr, int row, int col){

	/* Goto next row if column 9*/
	if(col == 9){
		col = 0;
		row++;
	}

	/* Checks if puzzle is complete */
	if(row == 9)
		return 0;

	/* See if square is already filled.
	If so, it returns whatever its child returns*/
	if (arr[row][col] != '0')
		 return su_solver(arr, row, col + 1);

	/* Tests numbers 1-9. If ok, then it
	calls recursively on itself */
	int k = 1;
	while(k <= 9){
		arr[row][col] = k + 48;
		if (ok(arr, row, col, k) == 0)
			if(su_solver(arr, row, col+1) == 0)
				return 0;

		k++;
	}
	arr[row][col] = '0';
	return -1;
}

/* Error message */
void err_sys(char* msg){
	perror(msg);
	exit(EXIT_FAILURE);
}
