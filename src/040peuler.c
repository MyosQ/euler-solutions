#include <stdio.h>
#include <stdlib.h>

int main(){

	int d = 1, one = 1, ten = -1, hundred = -1, thousand = -1, tenthousand = -1, hothousand = -1;

	char* champ = malloc(5000000*sizeof(char));
	printf("0.");
	while(hothousand < 5){

		if(hothousand >= 0){
//			printf("%d", hothousand);
			champ[d] = hothousand;
			d++;
		}
		if(tenthousand >= 0){
//			printf("%d", tenthousand);
			champ[d] = tenthousand;
			d++;
		}
		if(thousand >= 0){
//			printf("%d", thousand);
			champ[d] = thousand;
			d++;
		}
		if(hundred >= 0){
//			printf("%d", hundred);
			champ[d] = hundred;
			d++;
		}
		if(ten >= 0){
//			printf("%d", ten);
			champ[d] = ten;
			d++;
		}
		if(one >= 0){
//			printf("%d", one);
			champ[d] = one;
			d++;
		}
//		putchar('\n');

		one++;
		if(one > 9){
			if(ten == -1)
				ten += 2;
			else
				ten++;

			one = 0;
		}
		if(ten > 9){
			if(hundred == -1)
				hundred += 2;
			else
				hundred++;

			one = 0;
			ten = 0;
		}
		if(hundred > 9){
			if(thousand == -1)
				thousand += 2;
			else
				thousand++;

			one = 0;
			ten = 0;
			hundred = 0;
		}
		if(thousand > 9){
			if(tenthousand == -1)
				tenthousand += 2;
			else
				tenthousand++;

			one = 0;
			ten = 0;
			hundred = 0;
			thousand = 0;
		}
		if(tenthousand > 9){
			if(hothousand == -1)
				hothousand += 2;
			else
				hothousand++;

			one = 0;
			ten = 0;
			hundred = 0;
			thousand = 0;
			tenthousand = 0;
		}
	}
	printf("\nd(%d) = %d\n", 1, champ[1]);
	printf("\nd(%d) = %d\n", 10, champ[10]);
	printf("\nd(%d) = %d\n", 100, champ[100]);
	printf("\nd(%d) = %d\n", 1000, champ[1000]);
	printf("\nd(%d) = %d\n", 10000, champ[10000]);
	printf("\nd(%d) = %d\n", 100000, champ[100000]);
	printf("\nd(%d) = %d\n", 1000000, champ[1000000]);
	printf("\nProduct: %d\n", champ[1] * champ[10] * champ[100] * champ[1000] * champ[10000] * champ[100000] * champ[1000000]);

	return 0;
}
