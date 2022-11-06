/* Works without the last three functions!  */


#include <stdio.h>
#include <stdlib.h>
int hasStraightFlush(char p1[5][2], char p2[5][2]);
int hasFOK(char p1[5][2], char p2[5][2]);
int hasFullHouse(char p1[5][2], char p2[5][2]);
int hasFlush(char p1[5][2], char p2[5][2]);
int hasStraight(int p1s[5], int p2s[5]);
int hasTOK(int p1s[5], int p2s[5]);
int hasTwoPairs(int p1s[5], int p2s[5]);
int hasOnePair(int p1s[5], int p2s[5]);
int highestCard(int p1s[5], int p2s[5]);
int winner(char p1[5][2], char p2[5][2]);
void sort(char p1[5][2], int newarr[5]);
void selsort(int newarr[5]);

int hasStraightFlush(char p1[5][2], char p2[5][2]){

   return -1;
}
int hasFOK(char p1[5][2], char p2[5][2]){

   return -1;
}
int hasFullHouse(char p1[5][2], char p2[5][2]){

   return -1;
}
int hasFlush(char p1[5][2], char p2[5][2]){
   char p1suit = p1[0][1], p2suit = p2[0][1];
   int p1s[5], p2s[5];
   int p1T = 1, p2T = 1, a;

   for(a = 1; a < 5; a++){
      if(p1[a][1] != p1suit){
         p1T = 0;
         break;
      }
   }
   for(a = 1; a < 5; a++){
      if(p2[a][1] != p2suit){
         p2T = 0;
         break;
      }
   }
   printf("p1: %d   p2: %d   ", p1T, p2T);
   if(p1T == 0 && p2T == 0){
      printf("NO FLush :( \n");
      return -1;
   }
   if(p1T == 1 && p2T == 0){
      printf("p1 Flush......! \n");
      return 0;
   }
   if(p1T == 0 && p2T == 1){
      printf("p2 Flush........! \n");
      return 1;
   }

   printf("Both Flush.........................! \n");
   sort(p1, p1s);
   sort(p2, p2s);
   return highestCard(p1s, p2s);
}

int hasStraight(int p1s[5], int p2s[5]){
   int p1T = 1, p2T = 1, p1val = p1s[0], p2val = p2s[0], a;
   for(a = 1; a < 5; a++){
      if(p1s[a] != p1val + a){
         p1T = 0;
         break;
      }
   }
   for(a = 1; a < 5; a++){
      if(p2s[a] != p2val + a){
         p2T = 0;
         break;
      }
   }
   //printf("p1: %d   p2: %d   ", p1T, p2T);
   if(p1T == 0 && p2T == 0){
      //printf("NO Straight :( ");
      return -1;
   }
   if(p1T == 1 && p2T == 0){
      //printf("p1 Straight......! ");
      return 0;
   }
   if(p1T == 0 && p2T == 1){
      //printf("p2 Straight........! ");
      return 1;
   }
   //printf("Both Straight.........................! ");
   if(p1val == p2val)
      return -1;
   else
      return p1val > p2val ? 0 : 1;
}

int hasTOK(int p1s[5], int p2s[5]){
      int p1T = 0, p2T = 0, p1val, p2val, a;
      for(a = 0; a < 3; a++){
         if(p1s[a] == p1s[a+1] && p1s[a] == p1s[a+2]){
            p1T = 1;
            p1val = p1s[a];
            break;
         }
      }
      for(a = 0; a < 3; a++){
         if(p2s[a] == p2s[a+1] && p2s[a] == p2s[a+2]){
            p2T = 1;
            p2val = p2s[a];
            break;
         }
      }
      if(p1T == 0 && p2T == 0){
         return -1;
      }
      if(p1T == 1 && p2T == 0){
         return 0;
      }
      if(p1T == 0 && p2T == 1){
         return 1;
      }
      if(p1val == p2val)
         return highestCard(p1s, p2s);
      else
         return p1val > p2val ? 0 : 1;
}
int hasTwoPairs(int p1s[5], int p2s[5]){
   int p1T = 0, p2T = 0, p1High, p2High, p1Low, p2Low, a;
   for(a = 0; a < 4; a++){
      if(p1s[a] == p1s[a+1]){
         p1T++;
         if(a > 1)
            p1High = p1s[a];
         else
            p1Low = p1s[a];

         a++;
      }
   }
   for(a = 0; a < 4; a++){
      if(p2s[a] == p2s[a+1]){
         p2T++;
         if(a > 1)
            p2High = p2s[a];
         else
            p2Low = p2s[a];

         a++;
      }
   }
   if(p1T != 2 && p2T != 2){
      //printf("No Two PAIR :(\n");
      return -1;
   }
   if(p1T == 2 && p2T != 2){
      //printf("p1 Two PAIR!\n");
      return 0;
   }
   if(p1T != 2 && p2T == 2){
      //printf("p2 Two PAIR!\n");
      return 1;
   }
   if(p1T == 2 && p2T == 2){
      //printf("Both Two PAIR!\n"); ???
      if(p1High != p2High)
         return p1High > p2High ? 0 : 1;
      else if(p1Low != p1High)
         return p1Low > p2Low ? 0 : 1;
      else
         return highestCard(p1s, p2s);
   }

   return -1;
}
int hasOnePair(int arr1[5], int arr2[5]){
   int p1T = 0, p2T = 0, ind1, ind2, a;
   for(a = 0; a < 4; a++){
      if(arr1[a] == arr1[a+1]){
         p1T = 1;
         ind1 = a;
         break;
      }
   }
   for(a = 0; a < 4; a++){
      if(arr2[a] == arr2[a+1]){
         p2T = 1;
         ind2 = a;
         break;
      }
   }
   if(p1T == 0 && p2T == 0){
      //printf("NO pair :( ");
      return -1;
   }
   if(p1T == 1 && p2T == 0){
      //printf("p1 one pair! ");
      return 0;
   }
   if(p1T == 0 && p2T == 1){
      //printf("p2 one pair! ");
      return 1;
   }
   //printf("BOth pair! ");
   if(arr1[ind1] == arr2[ind2])
      return highestCard(arr1, arr2);
   else
      return arr1[ind1] > arr2[ind2] ? 0 : 1;
}
int highestCard(int p1s[5], int p2s[5]){
   int a;
   for(a = 4; a >= 0; a--){
      if(p1s[a] > p2s[a])
         return 0;
      if(p2s[a] > p1s[a])
         return 1;
   }
   return -1;
}

void sort(char p[5][2], int newarr[5]){
   char val;
   for(size_t i = 0; i < 5; i++){
      if(p[i][0] > '9'){
         switch (p[i][0]) {
            case 'T':
               val = 10;
            break;
            case 'J':
               val = 11;
            break;
            case 'Q':
               val = 12;
            break;
            case 'K':
               val = 13;
            break;
            case 'A':
               val = 14;
            break;
         }
      }
      else{
            val = p[i][0]-48;
         }
      newarr[i] = val;
   }
   selsort(newarr);
}

void selsort(int newarr[5]){
   int iMin, temp, q, k;
   for (q = 0; q < 4; q++) {
      iMin = q;
      for (k = q+1; k < 5; k++) {
         if(newarr[k] < newarr[iMin])
            iMin = k;
      }
      if(iMin != q){
         temp = newarr[iMin];
         newarr[iMin] = newarr[q];
         newarr[q] = temp;
      }
   }
}

int winner(char p1[5][2], char p2[5][2]){
   int ret;
   int sorted1[5], sorted2[5];
   sort(p1, sorted1);
   sort(p2, sorted2);

   if((ret = hasStraightFlush(p1, p2)) != -1)
      return ret; /* zero if p1, one if p2*/
   if((ret = hasFOK(p1, p2)) != -1)
      return ret; /* zero if p1, one if p2*/
   if((ret = hasFullHouse(p1, p2)) != -1)
      return ret; /* zero if p1, one if p2*/
   if((ret = hasFlush(p1, p2)) != -1){
      printf("  %c %c %c %c %c  ", p1[0][1], p1[1][1], p1[2][1], p1[3][1], p1[4][1]);
      printf("  %c %c %c %c %c  \n", p2[0][1], p2[1][1], p2[2][1], p2[3][1], p2[4][1]);
      return ret; /* zero if p1, one if p2*/
   }
   if((ret = hasStraight(sorted1, sorted2)) != -1){

      return ret; /* zero if p1, one if p2*/
   }
   if((ret = hasTOK(sorted1, sorted2)) != -1){
      return ret; /* zero if p1, one if p2*/
   }
   if((ret = hasTwoPairs(sorted1, sorted2)) != -1){
      return ret; /* zero if p1, one if p2*/
   }
   if((ret = hasOnePair(sorted1, sorted2)) != -1){
      return ret; /* zero if p1, one if p2*/
   }

   return highestCard(sorted1, sorted2);
}

int main(){
   int hand, q, p1WinCount = 0, p2WinCount = 0;
   char p1[5][2], p2[5][2];
   FILE* fp;
   if((fp = fopen("../input_files/054peuler.txt", "r")) == NULL){
      fprintf(stderr,"couldnt open file");
      exit(1);
   }

   for (hand = 0; hand < 1000; hand++){

      /* Read hands */
      for (q = 0; q < 5; q++){
         fscanf(fp, "%c%c ", &(p1[q][0]), &(p1[q][1]));
      }
      for (q = 0; q < 5; q++){
         fscanf(fp, "%c%c ", &(p2[q][0]), &(p2[q][1]));
      }

      if(winner(p1, p2) == 0){/*p1 wins*/
      //   printf(" p1 wins\n");
         p1WinCount++;
      }
      else{
         p2WinCount++;
      //   printf(" p2 wins\n");
      }
   }

   printf("wins by p1: %d\n", p1WinCount);
   printf("wins by p2: %d\n", p2WinCount);
   fclose(fp);
   return 0;
}
