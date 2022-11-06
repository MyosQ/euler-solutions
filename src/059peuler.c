#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
int decrypt(char* crypt, char* key, char* text, int len);

int main(){
	int a, b, c, encr_arr_length, index = 0, valid;
	FILE* fd;
	char* encr_arr = calloc(2000, sizeof(char));
	char* decr_arr = calloc(2000, sizeof(char));
	char* cp = NULL;
	char key[4];
	key[3] = '\0';

	if((fd = fopen("../input_files/059peuler.txt", "r")) == NULL){
		perror("Can't open file ");
		exit(0);
	}
	/* Read from file */
	while((fscanf(fd, "%d,", &a)) >= 0 && a != EOF){
		encr_arr[index] = a;
		index++;
	}
	encr_arr_length = index;
 	/*----------------*/

	/* try different keys */
	for(a = 97; a < 123; a++){
		for(b = 97; b < 123; b++){
			for(c = 97; c < 123; c++){
				key[0] = a;
				key[1] = b;
				key[2] = c;

				valid = decrypt(encr_arr, key, decr_arr, 50);
				cp = strstr(decr_arr, "the");

				if((valid >= 0) && cp)
					printf("key = %s   first fifty:%s\n\n\n", key, decr_arr);
			}
		}
	}

	/* get the total asciivalue of original text */
	char thekey[4];
	printf("Enter the key: ");
	fscanf(stdin, "%s", thekey);
	if(decrypt(encr_arr, thekey, decr_arr, encr_arr_length) < 0){
		printf("wrong key stupid\n");
		exit(0);
	}
	int totalsum = 0;
	for(a = 0; a < encr_arr_length; a++){
		totalsum += decr_arr[a];
	}

	printf("\ntotalsum = %d\n", totalsum);

	free(encr_arr);
	free(decr_arr);
	fclose(fd);
	return 0;

}

int decrypt(char* crypt, char* key, char* text, int length){

	int keyLen = 3;
	int keyIndex = 0;
	int index;
	int a;
	for(index = 0; index < length; index++){
		a = crypt[index] ^ key[keyIndex];
		if(a < 32 || a > 123 ){
			return -1;
		}
		text[index] = a;
		keyIndex = (index+1) % keyLen;
	}
	text[index] = '\0';
	return 0;
}
