#include <stdio.h>
//Get n bits from position p
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

int main(int argc, char **argv)
{
    unsigned x=0xFFFFFFFF;
    printf("3 bits from postion 4 are 0x%x\n",getbits(x,4,3));
	return 0;
}
