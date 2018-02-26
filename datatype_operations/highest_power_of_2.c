#include <stdio.h>
//Program to find the highest power of 2 smaller than or equal to n
int highestPowerOf2(int n)
{
    int res=0;
    int i;
    for(i=n;i>=1;i--)
    {
        printf("Before ...%d\n",i);
        if((i&(i-1))==0)
        {
            printf("After ...%d\n",i);
            res=i;
            break;
        }
    }
    return res;
}

int main()
{
    int n=16;
    printf("Index of highest power of 2 is %d\n",highestPowerOf2(n));
    return 0;
}
