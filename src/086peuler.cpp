#include <iostream>
#include <cmath>
#define ARRSIZE 100000000
bool squares[ARRSIZE];

using namespace std;

int main(int argc, char const *argv[]) {
   int a, b, c, pathSq, count, M, lim;

   for(a = 0; a < ARRSIZE; a++)
      squares[a] = 0;

   lim = (int)sqrt(ARRSIZE);
   for(a = 0; a <= lim; a++)
      squares[a*a] = 1;



   while(1){
      cout << "Enter maximum lenght of the sides: ";
      cin >> M;

      count = 0;
      for (c = 1; c <= M; c++){
         for(b = c; b <= M; b++){
            for(a = b; a <= M; a++){
               pathSq = a*a + (b+c)*(b+c);
               if(squares[pathSq]){
                  count ++;
               }
            }
         }
      }
      cout << "count: " << count << endl;
   }
   return 0;
}
