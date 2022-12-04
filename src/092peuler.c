/* Rather slow... */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int get_next_num(int num){
	char numstr[9];
	unsigned int i, nextnum = 0;
	sprintf(numstr,"%d", num);

	i = 0;
	while(1){
		if(numstr[i] == 0)
			break;

		else{
			nextnum += pow(numstr[i]-48, 2);
		}
		i++;
	}
	return nextnum;
}

int get_chain_end(int num, char* arr89, char* arr1){
	if(arr89[num] == 1)
		return 0;
	if(arr1[num] == 1)
		return -1;

	int temp[1000];
	int a, i = 0;
	while(num != 1 && num != 89){
		if(arr89[num] == 1){
			num = 89;
			break;
		}
		if(arr1[num] == 1){
			num = 1;
			break;
		}

		temp[i] = num;
		num = get_next_num(num);
		i++;
		if(i > 999){
			fprintf(stdout, "ERROR i");
			exit(1);
		}
	}
	if(num == 1){
		for(a = 0; a < i; a++){
			arr1[temp[a]] = 1;
		}
		return -1;
	}
	else{
		for(a = 0; a < i; a++){
			arr89[temp[a]] = 1;
		}
		return 0;
	}
}

int main(){
	unsigned int i, count = 0;
	char *arr89, *arr1;
	if((arr89 = calloc(10000000, sizeof(char))) == NULL)
		fprintf(stdout, "ERRORR");
	if((arr1 = calloc(10000000, sizeof(char))) == NULL)
		fprintf(stdout, "ERRORR");

	for(i = 1; i < 10000000; i++){
		if(get_chain_end(i, arr89, arr1) == 0)
			count++;
	}

	printf("Count: %d\n", count);

	return 0;
}
