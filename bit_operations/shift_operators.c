#include <stdio.h>

int main()
{
   char x[10];
   char y[10];
   x[0]=0xef;
   y[0]=0x4a;
   x[3]=0x7a;
   printf("\n value of msb is %x\n",((x[3]&0xf0)>>4));
   return 0;
}
