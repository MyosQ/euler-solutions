#include <stdio.h>
#include <stdlib.h>
#define ARRSIZE 80

struct cell{
   int val;
   int minPathSum ;
};

typedef struct cell cell;

int main(){
   FILE* fp;
   int a = 0, row = 0, col = 0, minSum;
   cell arr[ARRSIZE][ARRSIZE];

   /* Open file */
   if((fp = fopen("../input_files/081peuler.txt", "r")) == NULL){
      fprintf(stderr, "cant open file\n");
      exit(EXIT_FAILURE);
   }

   /* read into array */
   while(row < ARRSIZE){
      fscanf(fp, "%d", &a);
      arr[row][col].val = a;
      arr[row][col].minPathSum = -1;

      col ++;
      if((a = getc(fp)) == '\n'){
         row ++;
         col = 0;
      }
   }
   fclose(fp);

   /* Calc minPath */
   /* first column */
   for(row = 0; row < ARRSIZE; row++){
      arr[row][0].minPathSum = arr[row][0].val;
   }

   /* Other columns */
   for(col = 1; col < ARRSIZE; col++){
      
      /* Sideways */
      for(row = 0; row < ARRSIZE; row++){
         arr[row][col].minPathSum = arr[row][col-1].minPathSum + arr[row][col].val;
      }

      /* Down */
      for(row = 1; row < ARRSIZE; row++){
         if((arr[row-1][col].minPathSum + arr[row][col].val) < arr[row][col].minPathSum)
            arr[row][col].minPathSum = arr[row-1][col].minPathSum + arr[row][col].val;
      }

      /* Up */
      for(row = ARRSIZE-2; row >= 0; row--){
         if((arr[row+1][col].minPathSum + arr[row][col].val) < arr[row][col].minPathSum)
            arr[row][col].minPathSum = arr[row+1][col].minPathSum + arr[row][col].val;
      }
   }

   /* print array *//*
   for(row = 0; row < ARRSIZE; row++){
      for(col = 0; col < ARRSIZE; col++){
         printf("%d ", arr[row][col].minPathSum);
      }
      putchar('\n');
   }*/

   /* find least value in last column */
   minSum = arr[0][ARRSIZE-1].minPathSum;
   for(row = 0; row < ARRSIZE; row++){
      if(arr[row][ARRSIZE-1].minPathSum < minSum){
         minSum = arr[row][ARRSIZE-1].minPathSum;
      }
   }

   printf("min path sum:  %d\n", minSum);

   return 0;
}
