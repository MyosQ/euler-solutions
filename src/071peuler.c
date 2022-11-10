#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
/* gets correct answer dispite not using the gcd function... */

/* a > b */
int gcd(int a, int b){
   int z;
   z = a % b;
   if (z == 0)
      return b;
   else
      return gcd(b, z);
}

int main(){
   uint64_t n, d;
   uint64_t nMax = 1, dMax = 9900000;


   for(d = 1000000; d >= 990000; d--){
      n = (int)(d/3);
      while(n*7 < d*3){
         n++;
      }
      if((n-1)*dMax > d*nMax){
         nMax = (n-1);
         dMax = d;
         printf("%"PRIu64"/%"PRIu64"\n", n-1, d);
      }
   }


   return 0;
}
