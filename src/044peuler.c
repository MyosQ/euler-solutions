#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int isPent(int num){
   int sq;
   /*test 1*/
   sq = 24*num + 1;
   if(sq != floor(sqrt(sq))*floor(sqrt(sq)))
      return -1;

   /*test 2*/
   if((int)floor(sqrt(sq)) % 6 != 5)
      return -1;

   return 0;
}

int main(){
   int a;
   uint64_t* pent = calloc(100000, sizeof(uint64_t));
   for(a = 0; a < 100000; a++){
      pent[a] =  (a+1)*(3*(a+1)-1)/2;
   }
   //f//or(a = 0; a < 10; a++){
   //   printf("%d\n",pent[a]);
   //}

   int dist;
   for(dist = 1; dist < 50000; dist++){
      for(a = 0; a < 100000-dist; a++){
         if(isPent(pent[a] + pent[a+dist]) == 0 && isPent(pent[a+dist] - pent[a]) == 0){
            printf("%"PRIu64" %"PRIu64"\n", pent[a], pent[a+dist]);
            printf("Diff: %"PRIu64"\n", pent[a+dist]-pent[a]);
         }
      }
   }

   return 0;
}
