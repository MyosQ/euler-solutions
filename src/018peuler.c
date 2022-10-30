#include <stdio.h>
#include <stdlib.h>
#define TRIANGLE_SIZE 15

typedef struct values{
	unsigned int weight;
	unsigned int maxRoute;
	struct values* maxRouteParent;
}values;

values* getMaxParent(values* a, values* b){
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;
	if(a->maxRoute > b->maxRoute)
		return a;
	else
		return b;
}

int main(){
	FILE* fd;
	int a, b, row = 0, col = 0;
	unsigned int totalMaxRoute = 0;
	values* temp;

	/* Allocate the array */
	values*** arr = calloc(TRIANGLE_SIZE + 1, sizeof(values**));
	for(a = 0; a < TRIANGLE_SIZE; a++)
		arr[a] = calloc(TRIANGLE_SIZE + 1, sizeof(values*));

	/* Open file */
	if((fd = fopen("../input_files/018peuler.txt", "r")) == NULL){
		perror("Cant open file");
		exit(EXIT_FAILURE);
	}

	/* Read into array */
	while(fscanf(fd, "%d", &a) > 0){
		temp = calloc(1, sizeof(values));
		temp->weight = a;
		arr[row][col] = temp;

		if(getc(fd) == '\n'){
			row++;
			col = 0;
		}
		else
			col ++;
	}


	/* Dijkstras algorithm */
	arr[0][0]->maxRoute = arr[0][0]->weight; // special for root
	row = 1;
	col = 0;
	while(row < TRIANGLE_SIZE){

		/* Left edge */
		if(col == 0){
			arr[row][col]->maxRoute = arr[row][col]->weight + arr[row - 1][col]->maxRoute;
			arr[row][col]->maxRouteParent = arr[row-1][col];
		}

		/* else */
		else{
			temp = getMaxParent(arr[row-1][col], arr[row-1][col-1]);
			arr[row][col]->maxRoute = arr[row][col]->weight + temp->maxRoute;
			arr[row][col]->maxRouteParent = temp;
		}


		/* New row if last column */
		col++;
		if(arr[row][col] == NULL){
			col = 0;
			row++;
		}
	}



	for(a = 0; a < TRIANGLE_SIZE; a++)
		if(arr[TRIANGLE_SIZE - 1][a]->maxRoute > totalMaxRoute)
			totalMaxRoute = arr[TRIANGLE_SIZE - 1][a]->maxRoute;

	printf("total max route: %u\n", totalMaxRoute);


	/* Freeing */
	for(a = 0; a < TRIANGLE_SIZE; a++){
		for(b = 0; b < TRIANGLE_SIZE; b++)
			if(arr[a][b] != NULL)
				free(arr[a][b]);
		free(arr[a]);
	}
	free(arr);
	fclose(fd);
	return 0;
}
