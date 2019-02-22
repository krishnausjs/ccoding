#include <stdio.h>
//Get n bits from position p
unsigned getbits(unsigned x, int p, int n)
{
   //return (x >> (p+1-n)) & ~(1 << n);
   return     ((x>>p) & (~(~0<<n)));
   //return (((1 << n) - 1) & (n >> (p - 1)));
}

//Function setbits(x,p,n,y) that returns x with the n bits that begin at position p
//set to right most n bits of y, leaving the other bits unchanged.
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return x & ~(~(1 << n) << (p+1-n)) |
          (y & ~(1 << n)) << (p+1-n); 
}
int main(int argc, char **argv)
{
    unsigned x=0xAB;
    unsigned y=0x7;
    int i;
    printf("3 bits from postion 4 are 0x%x\n",getbits(x,4,3));
    
    printf("Setting bits 5 that begin at position 1 right most 5 bits of y. Value of x is 0x%x\n",setbits(x,5,3,y));
    for(i=0; i<10; i++)
        printf("Value of 1<<%d is 0x%x(%d)\n",i,(1 << i),(1 << i));

    for(i=0; i<10; i++)
        printf("Value of 1>>%d is 0x%x(%d)\n",i,(1 >> i),(1 >> i));  
  
    printf("Value of (1<<3) is %d\n",(1<<3));
    printf("Value of ~(1<<3) is 0x%x\n",~(1<<3));
	return 0;
}
