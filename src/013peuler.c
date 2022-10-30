#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int addTwo(char* str1, char* str2, char* sum);


int main(){
	FILE* fd;
	int c, arrlen,a = 0;

	/* Allocate arrays */
	char** arr = calloc(101, sizeof(char*));
	for(c = 0; c < 101; c++)
		arr[c] = calloc(51, sizeof(char));
	char *sum = calloc(70, sizeof(char));

	/* Open file */
	if((fd = fopen("../input_files/013peuler.txt", "r")) == NULL){
		perror("Can't open file");
		exit(-1);
	}
	/* Scan into array */
	while((fscanf(fd, "%s\n", arr[a])) > 0)	a++;


	/* Add everything */
	arrlen = a;
	addTwo(arr[0], arr[1], sum);

	for(a = 2; a < arrlen; a++)
		if(addTwo(sum, arr[a], sum) < 0){
			fprintf(stderr, "Error: adding empty strings\n");
			exit(0);
		}

	printf("Sum: %s\n", sum);

	/* Free allocated arrays */
	for(c = 0; c < 101; c++)
		free(arr[c]);
	free(arr);
	free(sum);
	fclose(fd);
	return 0;
}
