#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

int phi(int n){
   int p, res = n;
   for(p = 2; p*p <= n; p++){
      if (n % p == 0){
         res *= (1 - (1/(double)p));

         while(n % p == 0){
            n /= p;
         }
      }
   }
   if (n > 1)
     res *= (1 - (1 / (double)n));

   return (int)res;
}


int main(){
   int a;

   uint64_t sum = 0;
   for(a = 2; a <= 1000000; a++){
      sum += phi(a);
   }

   printf("%"PRIu64"\n", sum);

   return 0;
}
