#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	FILE* fd = fopen("../input_files/022peuler.txt", "r");
	int c;
	int a;
	int row = 0;
	int col = 0;


	char** array = calloc(10000, sizeof(char*));
	for(a = 0; a < 10000; a++){
		array[a] = calloc(50, sizeof(char));
	}

	/* Read into array */
	c = getc(fd); // forward 1
	while((c = getc(fd)) != EOF){
		if(c == '"'){
			getc(fd);
			getc(fd);
			row ++;
			col = 0;
		}
		else {
			array[row][col] = c;
			col ++;
		}
	}
	int numrows = row;

	/*insertion sort*/
	int b;
	char* temp;
	int lenght;
	for(a = 1; a < numrows; a++){
		b = a;

		while((b > 0) && (strncmp(array[b], array[b-1], max(strlen(array[b]), strlen(array[b-1]))) < 0)){
			temp = array[b];
			array[b] = array[b-1];
			array[b-1] = temp;
			b--;
		}
	}
	/* get namescores */
	int nameScore[numrows];
	int colIndex;
	int sum;
	for(a = 0; a < numrows; a++){
		colIndex = 0;
		sum = 0;
		while(array[a][colIndex] != '\0'){
			sum += (int)array[a][colIndex] - 64;
			colIndex ++;

		}
		nameScore[a] = sum;
	}

	/* calculate totalsum*/
	unsigned long totalSum = 0;
	for(a = 0; a < numrows; a++){
		totalSum += nameScore[a] * (a+1);
	}
	printf("%lu\n", totalSum);

	/* freeing array */
	for(a = 0; a < 5000; a++){
		free(array[a]);
	}
	free(array);
	exit(0);
}
