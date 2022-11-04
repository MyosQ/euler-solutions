#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void itoa(int num, char* arr){
	snprintf(arr, 7, "%d", num);
}
void itobina(int num, char* arr){
	int index = 0;
	while(num != 0){
		arr[index] = (num % 2) + 48;
		num /= 2;
		index ++;
	}
	arr[index] = '\0';

}
int mystrlen(char* arr){
	int len = 0, i = 0;
	while(arr[i] != '\0'){
		i++;
		len ++;
	}
	return len;
}

void strrev(char* arr){
	int a;
	char temp;
	int len = mystrlen(arr);
	for(a = 0; a < len/2 ; a++){
		temp = arr[len - 1 - a];
		arr[len - 1 - a] = arr[a];
		arr[a] = temp;
	}
}

int main(){

	int a, totalsum = 0;
	char dec_array[7], bin_array[21], dec_array_rev[7], bin_array_rev[21];

	for(a = 1; a < 1000000; a+=2){
		itoa(a, dec_array);
		itobina(a, bin_array);

		strcpy(dec_array_rev, dec_array);
		strcpy(bin_array_rev, bin_array);

		strrev(dec_array_rev);
		strrev(bin_array_rev);

		if(!strcmp(dec_array, dec_array_rev) && !strcmp(bin_array, bin_array_rev)){
			printf("palindromic nr: %d   binary: %s\n", a, bin_array_rev);
			totalsum += a;
		}
	}
	printf("totalsum: %d\n", totalsum);
	return 0;
}
