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
   int count = 0;

   for(d = 1; d <= 12000; d++){
      for(n = 1; n <= (int)(d/2); n++){
         if(n*3 > d && n*2 < d && gcd(d, n) == 1){
            //printf("%"PRIu64"/%"PRIu64"\n", n, d);
            count++;
         }
      }
   }

   printf("count: %d\n", count);
   return 0;
}
