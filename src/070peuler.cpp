#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

#define ARRSIZE 10000000

void minPrimesfunc(int size, int arr[]){
   int i, j;
   for(i = 0; i < size; i++){
      arr[i] = 1;
   }

   for(i = 2; i*i <= size; i++){
      if(arr[i] == 1){ //Prime
         for(j = i*i; j < size; j += i){
            if(arr[j] == 1){
               arr[j] = i;
            }
         }
      }
   }
   for(i = 0; i < size; i++){
      if(arr[i] == 1){
         arr[i] = i;
      }
   }
}

int phi(int n, int size, int minPrimes[]){

   int a, minP, res = n;
   a = n;
   while(a != 1){
      minP = minPrimes[a];
      res -= res/minP;

      while(a % minP == 0){
         a /= minP;
      }
   }
   return res;
}


int main(int argc, char const *argv[]) {
   int *minPrimes, i, n, phiNum, minN = 0;
   double minRatio = 2, ratio;
   string nString, phiString;
   minPrimes = (int*)malloc(ARRSIZE * sizeof(int));
   minPrimesfunc(ARRSIZE, minPrimes);

   for(n = 2; n < ARRSIZE; n++){
      phiNum = phi(n, ARRSIZE, minPrimes);

      nString = std::to_string(n);
      phiString = to_string(phiNum);

      sort(nString.begin(), nString.end());
      sort(phiString.begin(), phiString.end());

      if(nString == phiString){

         ratio = (double)n/phiNum;
         if(ratio < minRatio){
            minRatio = ratio;
            minN = n;
         }
      }
   }

   cout << minN << "  " << minRatio << endl;
   return 0;
}
