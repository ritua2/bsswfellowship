#include <iostream>
#include <unistd.h>

void b (int &);
void d (int &);
int main() {
   int i1 = 10;
   int i2 = 20;
   d(i1);
   b(i2);
   b(i1);
   printf("Final i1 = %d\n", i1);
   printf("Final i2 = %d\n", i2);
   return 1;
}
void b (int & v) {
   for(int i =0 ; i < 10; i++) {
      v+=i;
      printf("Value changed to %d\n", v );
      sleep(1);
   }
}
void d (int & v) {
   for (int i =0; i < 10; i++) {
      b(v);
   }
}
