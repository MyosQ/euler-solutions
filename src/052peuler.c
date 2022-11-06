#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cdigits(int n1, int n2, int len){
   int i;
   char digMem1[10], digMem2[10], num1[len+1], num2[len+1];
   memset(digMem1, 0, 10);
   memset(digMem2, 0, 10);
   snprintf(num1, len+1, "%d", n1);
   snprintf(num2, len+1, "%d", n2);

   /* see numbers */
   for(i = 0; i < len; i++){
      digMem1[(num1[i]-48)] += 1;
   }
   for(i = 0; i < len; i++){
      digMem2[(num2[i]-48)] += 1;
   }
   /*compare*/
   for(i = 0; i < 10; i++){
      if(digMem1[i] != digMem2[i])
         return -1;
   }
   return 0;
}

int main(){
   unsigned int a;
   int digits;
   int lim = 10000;
   for(a = 1000; a < 4600000; a++){
      digits = floor(log10(a))+1;
      if(cdigits(a, 2*a, digits) == 0)
         if(cdigits(a, 3*a, digits) == 0)
            if(cdigits(a, 4*a, digits) == 0)
               if(cdigits(a, 5*a, digits) == 0)
                  if(cdigits(a, 6*a, digits) == 0)
                     printf("%d\n", a);

      if(a > lim/6){
         a = lim+1;
         lim *= 10;
      }

   }
   return 0;
}
