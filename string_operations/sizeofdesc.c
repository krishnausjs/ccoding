#include <stdio.h>

typedef unsigned long uint32_t;
#define ALIGN_VALUE(value,align)  (((uint32_t)(value)+(align-1))&(~(align-1)))

typedef struct 
{
    unsigned long a;
    unsigned char *ptr;
}struct_a;
int main()
{
    struct_a str;
    unsigned long x;
    printf("sizze of x is %d\n",sizeof(x));
    printf("sizze a in structure %x\n",sizeof(str.a));
    printf("Value of ALLIN is %x\n",ALIGN_VALUE(1024,64));
    printf("sizze is %x\n",sizeof(str));
}
