#include <stdio.h>
#include <math.h>
#include <string.h>

void reverse(char num[], char num2[]){
   int a, len = strlen(num);

   for(a = 0; a < len; a++){
      num2[a] = num[len-1-a];
   }
   num2[len] = '\0';
}

int isPalin(char num[]){
   int a, len = strlen(num);
   char num2[len];

   for(a = 0; a < len; a++){
      num2[a] = num[len-1-a];
   }
   num2[len] = '\0';

   if(strncmp(num, num2, len) == 0)
      return 0;

   return -1;
}

int isLynchrel(char num[], int iter){
   char num2[50];
   char sum[50];
   if(iter > 1 && isPalin(num) == 0)
      return 0;

   if(iter >= 50)
      return -1;

   reverse(num, num2);
   addTwo(num, num2, sum);
   printf("%d, %s + %s = %s\n", iter, num, num2, sum);
   return isLynchrel(sum, iter+1);
}

int main(){

   int a;
   char num[50];
   int count = 0;
   for(a = 1; a < 10000; a++){

      snprintf(num, 50, "%d", a);
      if(isLynchrel(num, 1) != 0){
         count ++;
      }
   }
   printf("count: %d\n", count);
   return 0;
}
