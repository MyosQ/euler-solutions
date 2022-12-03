#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX_ROLLS 100000

int comChest(int CCcount, int currentSquare){
   int newSquare;
   /* 2/16 chance */
   if(CCcount % 16 == 1){
      /*Advance to GO*/
      cout << "Advance to go!" << endl;
      newSquare = 0;
   }
   else if(CCcount % 16 == 2){
      /* Go to Jail */
      cout << "go to Jail!"<< endl;
      newSquare = 10;
   }
   else{
      newSquare = currentSquare;
   }
   return newSquare;

}

int chance(int CHcount, int CCcount, int currentSquare){
   int newSquare;
   /* 10/16 chance */
   switch(CHcount % 16){
      case 1: newSquare = 0; break;cout << "Advance to go!" << endl;
      case 2: newSquare = 10; break;cout << "go to Jail!" << endl;
      case 3: newSquare = 11; break;
      case 4: newSquare = 24; break;
      case 5: newSquare = 39; break;
      case 6: newSquare = 5; break;
      case 7: // go to next station
      case 8: // go to next station
         newSquare = currentSquare - (currentSquare % 5);
         if(newSquare % 2 == 0) newSquare = (newSquare + 5) % 40;
         else newSquare = (newSquare + 10) % 40;
         break;
      case 9: // go to next utility
         if(currentSquare < 28 && currentSquare > 12) newSquare = 28;
         else newSquare = 12;
         break;
      case 10:
         /* Go back 3 steps */
         newSquare = currentSquare - 3;
         if(newSquare < 0) newSquare += 40;

         if(currentSquare == 33){
            newSquare = comChest(CCcount, newSquare);
            CCcount++;
         }
         break;

      default: newSquare = currentSquare;
   }
   return newSquare;
}

int main(int argc, char const *argv[]) {
   int a, dice1, dice2, dieSum, roll, square = 0, inRowCount = 0;
   int squareProb[40];
   int CHcount = 0, CCcount = 0;
   memset(squareProb, 0, sizeof(squareProb));

   /* Init rand seed */
   srand(time(NULL));

   for(roll = 0; roll < MAX_ROLLS; roll++){

      /* Roll dice */
      dice1 = rand() % 4 + 1;
      dice2 = rand() % 4 + 1;
      dieSum = (dice1 + dice2);
      cout << "Roll: " << roll << ", " << dieSum << "  Chance- and comchest-count: "<< CCcount << ", "<< CHcount<< endl;

      /* Check if 3 in a row */
      if(dice1 == dice2)
         inRowCount++;
      else
         inRowCount = 0;

      if(inRowCount == 3){
         // Go to Jail
         cout << "3 in a row! Go to jail!" << endl;
         square = 10;
         squareProb[square]++;
         inRowCount = 1;
         continue;
      }

      /* Move the piece */
      square = (square + dieSum)  % 40;
      cout << "lands on square " << square << endl;


      /* Special squares */
      /* Jail */
      if(square == 30){
         /* Go to jail! */
         cout << "Go to jail!" << endl;
         square = 10;
      }

      /* Community chest */
      else if(square == 2 || square == 17 || square == 33){
            /* CC1, CC2, CC3 */
            cout << "Comchest!" << endl;
            square = comChest(CCcount, square);
            CCcount++;
            cout << "landed on " << square << endl;
      }

         /* Chance */
      else if(square == 7 || square == 22 || square == 36){
            /*CH1, CH2, CH3*/
            cout << "Chance!" << endl;
            square = chance(CHcount, CCcount, square);
            CHcount++;
            cout << "landed on " << square << endl;
      }



      /* piece has landed */
      squareProb[square]++;

      //cin.ignore();
      cout << endl;
   }



   /* Print results */
   int sum = 0;
   for (size_t i = 0; i < 40; i++) {
      cout << i << ": " << (double)(squareProb[i])/(double)MAX_ROLLS << endl;
      sum += squareProb[i];
   }
   cout << "sum" << sum << endl;

   double max = 0;
   int amax = 0;
   cout << "top 3: " << endl;
   for(int i = 0; i < 3; i++){
      for(int a = 0; a < 40; a++){
         if (squareProb[a] > max){
            max = squareProb[a];
            amax = a;
         }
      }
      cout << amax << ": " << squareProb[amax] << endl;
      squareProb[amax] = 0;
      max = 0;
      amax = 0;
   }

   return 0;
}
