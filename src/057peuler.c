#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 1000

int addTwo(char* str1, char* str2, char* sum);

int main(){
   unsigned int a, count = 0;
   char *temp, *numerator, *denominator;
   numerator = calloc(SIZE, sizeof(char));
   denominator = calloc(SIZE, sizeof(char));
   numerator[0] = '3';
   denominator[0] = '2';

   for(a = 0; a < 1000; a++){
      addTwo(numerator, denominator, numerator);
      temp = denominator;
      denominator = numerator;
      numerator = temp;
      addTwo(numerator, denominator, numerator);

      if(strlen(numerator) > strlen(denominator))
         count++;
   }

   printf("Count: %d\n", count);
   return 0;
}
