#include <stdio.h>


void printArray(int arr[], int ind){
   int a;
   for(a = 0; a < ind; a++){
      printf("%d ", arr[a]);
   }
   printf("\n");
}

int getPartition(int n){
   int count = 0, remVal, ind = 0, p[n];
   p[ind] = n;

   while (1){

      //printArray(p, ind+1);
      count ++;

      remVal = 0;
      while (ind >= 0 && p[ind] == 1){
         remVal ++;
         ind--;
      }

      /* if ind < 0, all the values are 1 so there are no more partitions */
      if (ind < 0)
         break;

      /* Decrease the p[k] found above and adjust the remValue */
      p[ind] --;
      remVal ++;

      /* Add all the amount in remval to the array. As big ass possible */
      while (remVal > p[ind]){
            p[ind+1] = p[ind];
            remVal -= p[ind];
            ind ++;
      }

      /* Add the remainder of remVal */
      p[ind+1] = remVal;
      ind++;
    }
    return count;
}

int main(){
   int c = getPartition(100);
   printf("count: %d - 1 = %d\n", c, c-1);
   return 0;
}
