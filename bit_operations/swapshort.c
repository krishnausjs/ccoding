#include <stdio.h>

#define swapshort(x) ((((x)&0xff00)>>8)|(((x)&0x00ff)<<8))

int main()
{
    short shortbyte=0x6070;
    printf("Before swapping %x\n",shortbyte);
    printf("After swapping %x\n",swapshort(shortbyte));
    return 0;
}
