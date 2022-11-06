#include <stdio.h>
#include <stdlib.h>
#define ARRSIZE 201
int digitsum(int pow, int exp);

int main(){
   int digSum, maxSum = 0, a, b;
   for(a = 75; a < 100; a++){
      for(b = 75; b < 100; b++){
         if((digSum = digitsum(a, b)) > maxSum)
            maxSum = digSum;
      }
   }


   printf("maxSum: %d\n", maxSum);
   return 0;
}


int digitsum(int pow, int exp){
   int a, b, carry, res, digSum = 0;
   char *arr = calloc(ARRSIZE, sizeof(char));
   arr[0] = 1;
   for(a = 0; a < exp; a++){
      carry = 0;
      for(b = 0; b < ARRSIZE; b++){
            res = arr[b]*pow + carry;
            arr[b] = res % 10;
            carry = res / 10;
      }
   }
   for(a = ARRSIZE-1; a >= 0; a--){
      digSum += arr[a];
   }
   return digSum;
}
