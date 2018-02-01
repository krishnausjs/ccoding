#include <stdio.h>
int NumberOfSetBits(int i);
int main()
{
	int  x=0xffffffff;
        printf("\n Number of set bits = %d\n",NumberOfSetBits(x));
        return 0;
}
int NumberOfSetBits(int i)
{
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}
