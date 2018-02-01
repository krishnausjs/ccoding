#include <stdio.h>
#define MIN(A,B) (A<B)?A:B
int main()
{
    int a=10,b=12;
    int *p;
    p=&a;

    printf("Address of a is 0x%x and b is 0x%x \n",&a,&b);
    //printf("Value of a and b is %d and %d p is 0x%x\n",a,b,p);
    //printf("Minimum of a and b is %d p is 0x%x \n",MIN(a,b),p);
    //printf("p is 0x%x, *p is %d, *p++ is %d,*p is %d,  p is 0x%x\n ",p,*p,++*p,*p,p);
    //printf("p is 0x%x \n *p is %d \n *p++ is %d \n *p is %d \n  p is 0x%x\n ",p,*p,++*p,*p,p);
    printf("p is 0x%x \n *p is %d \n *p++ is %d \n *p is %d \n  p is 0x%x\n ",p,*p,++*p,*p,p);
    //printf("p is 0x%x \n ",p);
    //printf("*p is %d \n",*p);
    //printf("*p++ is %d \n",++*p);
    //printf("*p is 0x%x \n ",p);
    //printf("*p is %d, ++*p is %d  p is 0x%x, value of *p++ is %d, value of p is 0x%x\n ",*p,++*p,p,*p++,p);
    //printf("Value of a and b is %d and %d p is 0x%x\n",a,b,p);
    //printf(" *p++ is %d  p is 0x%x\n",*p++,p);
    //printf("Value of a and b is %d and %d p is 0x%x value of *p is %d\n",a,b,p,*p);
    return 0;
}
