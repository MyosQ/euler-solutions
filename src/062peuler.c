#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#define LIM 15000

void getPermArr(char* num, char* arr){
   int a, len = strlen(num);
   for(a = 0; a < len; a++)
      arr[num[a] - 48]++;
}

int main(){

   uint64_t a, b, count;
   uint64_t *cubes;
   char num[20], num2[20], digarr[11], digtestarr[11];

   /* allocate */
   if((cubes = malloc((LIM+2) * sizeof(uint64_t))) == NULL){
      fprintf(stderr, "couldnt allocate\n");
      exit(1);
   }
   /* calculate cubes */
   for(a = 0; a < LIM; a++){
      cubes[a] = a*a*a;
   }

   /* see if any cubes are perms of eachother */
   for(a = 0; a < LIM; a++){
      
      sprintf(num, "%"PRIu64, cubes[a]);
      memset(digarr, 48, 10);
      digarr[10] = 0;
      getPermArr(num, digarr);

      count = 0;
      for(b = 0; b < LIM; b++){

         sprintf(num2, "%"PRIu64, cubes[b]);
         memset(digtestarr, 48, 10);
         digtestarr[10] = 0;
         getPermArr(num2, digtestarr);

         if(!strncmp(digarr, digtestarr, 10))
            count ++;

      }
      if(count == 5){
         printf("%"PRIu64"\n", cubes[a]);
         return 0;
      }
   }

   printf("Nothing found :(\n");
   return 0;
}
