/* Really messy, preferablly to use some kind of big-integer library */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#define intbuffer 10000000000

void add_to_next(int64_t* numa, int64_t* numb){
   int64_t over, a, b;
   a = *numa;
   b = *numb;
   if(a / intbuffer > 0){
      if(b < 0)
         b = 0;

      over = a / intbuffer;
      b += over;
      a -= over * intbuffer;
   }
   *numa = a;
   *numb = b;
}

int getdigitsum(int64_t a){
   int i, sum = 0;
   char numbuf[10];
   memset(numbuf, 0, 10);
   snprintf(numbuf, 11, "%"PRId64"", a);
   for(i = 0; i < 10; i++){
//      printf("%d ", numbuf[i]-48);
      if(numbuf[i] != 0)
         sum += numbuf[i] - 48;
   }
   return sum;
}

int main(){
   int i, dsum;
   int64_t a = 1, b = -1, c = -1, d = -1, e = -1, f = -1, g = -1, h = -1;
   int64_t j = -1, k = -1, l = -1, m = -1, n = -1, o = -1, p = -1, q = -1, r = -1;

   for(i = 1; i <= 100; i++){
      a *= i;

      if(b > 0){
         b *= i;
      }
      if(c > 0){
         c *= i;
      }
      if(d > 0){
         d *= i;
      }
      if(e > 0){
         e *= i;
      }
      if(f > 0){
         f *= i;
      }
      if(g > 0){
         g *= i;
      }
      if(h > 0){
         h *= i;
      }
      if(j > 0){
         j *= i;
      }
      if(k > 0){
         k *= i;
      }
      if(l > 0){
         l *= i;
      }
      if(m > 0){
         m *= i;
      }
      if(n > 0){
         n *= i;
      }
      if(o > 0){
         o *= i;
      }
      if(p > 0){
         p *= i;
      }
      if(q > 0){
         q *= i;
      }
      if(r > 0){
         r *= i;
      }

      add_to_next(&a, &b);
      add_to_next(&b, &c);
      add_to_next(&c, &d);
      add_to_next(&d, &e);
      add_to_next(&e, &f);
      add_to_next(&f, &g);
      add_to_next(&g, &h);
      add_to_next(&h, &j);
      add_to_next(&j, &k);
      add_to_next(&k, &l);
      add_to_next(&l, &m);
      add_to_next(&m, &n);
      add_to_next(&n, &o);
      add_to_next(&o, &p);
      add_to_next(&p, &q);
      add_to_next(&q, &r);

   }
      printf("a: %"PRId64"  b: %"PRId64"  c: %"PRId64"\n", a, b, c);
      printf("d: %"PRId64"  e: %"PRId64"  f: %"PRId64"\n", d, e, f);
      printf("g: %"PRId64"  h: %"PRId64"  j: %"PRId64"\n", g, h, j);
      printf("k: %"PRId64"  l: %"PRId64"  m: %"PRId64"\n", k, l, m);
      printf("n: %"PRId64"  o: %"PRId64"  p: %"PRId64"\n", n, o, p);
      printf("q: %"PRId64"  r: %"PRId64"\n", q, r);

   dsum = 0;
   dsum += getdigitsum(a);
   dsum += getdigitsum(b);
   dsum += getdigitsum(c);
   dsum += getdigitsum(d);
   dsum += getdigitsum(e);
   dsum += getdigitsum(f);
   dsum += getdigitsum(g);
   dsum += getdigitsum(h);
   dsum += getdigitsum(j);
   dsum += getdigitsum(k);
   dsum += getdigitsum(l);
   dsum += getdigitsum(m);
   dsum += getdigitsum(n);
   dsum += getdigitsum(o);
   dsum += getdigitsum(p);
   dsum += getdigitsum(q);

   printf("dsum: %d\n", dsum);

   return 0;
}
