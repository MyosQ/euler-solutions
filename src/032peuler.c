#include <stdio.h>
#include <string.h>

void check_mul(char palin[]){
	int a;
	if((palin[0]*10 + palin[1]*1) * (palin[2]*100 + palin[3]*10 + palin[4]*1) == palin[5]*1000 + palin[6]*100 + palin[7]*10 + palin[8]*1){
		for(a = 0; a < 9; a++){
			if(a == 2 || a == 5)
				printf(" ");

			printf("%d", palin[a]);
		}

		printf("\n");
	}
	if((palin[0]*1) * (palin[1]*1000 + palin[2]*100 + palin[3]*10 + palin[4]*1) == palin[5]*1000 + palin[6]*100 + palin[7]*10 + palin[8]*1){
		for(a = 0; a < 9; a++){
			if(a == 1 || a == 5)
				printf(" ");

			printf("%d", palin[a]);
		}
		printf("\n");
	}
}

void rec_fill(char palin[], int index, char isTaken[]){
	int a;

	if(index == 9){
		check_mul(palin);
		return;
	}


	for(a = 0; a < 9; a++){
		if(isTaken[a] == 0){
			palin[index] = (a + 1);
			isTaken[a] = 1;

			rec_fill(palin, index + 1, isTaken);
			isTaken[a] = 0;
		}
	}

}

int main(){
	int n;
	char palin[9];
	char isTaken[9];
	memset(palin, 0, 9);
	memset(isTaken, 0, 9);

	n = 0;
	rec_fill(palin, n, isTaken);

	return 0;
}
