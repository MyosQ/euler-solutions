#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isNPandig(int a){
   int i, n = 7, pandig = 0;
   char num[8];
   snprintf(num, 8, "%d", a);

   /* remove those that cant be prime */
   if((num[6]-48) == 5)
      return -1;

   if((num[0]+num[1]+num[2]+num[3]+num[4]+num[5]+num[6] - 48*7) % 3 == 0)
      return -1;


   /* see if pandig */
   for(i = 0; i < 7; i++){
      if((num[i]-48) == 0 || (num[i]-48) == 9 || (num[i]-48) == 8)
         return -1;

      if((1 << (num[i]-48)) & pandig)
         return -1;
      else
         pandig = pandig | (1 << (num[i]-48));
   }

   //printf("%s   ", num);
   //printf("%d   \n", pandig);
   return 0;
}

int myPowMod(int a, int pow, int mod){

	int i, ans = 1;
	for(i = 0; i < pow; i++){
		ans = (ans * a) % mod;
	}

	return ans;
}

int isPrime(int a){

	if(myPowMod(2, a-1, a)  == 1)
		return 0;
	else
		return -1;
}

int main(){
   int a;
   for (a = 7654321; a > 1; a -= 2){
      if(isNPandig(a) == 0){
         if(isPrime(a) == 0){
            printf("%d\n", a);
         //   break;
         }
      }
   }


   return 0;
}
