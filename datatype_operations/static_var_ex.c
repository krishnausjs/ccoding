#include <stdio.h>

int call_function(int x);

int main()
{
   int i;
   for(i=0;i<10;i++)
   call_function(i);
}

int call_function(int x)
{
    static int y;
    printf("\n Value of x is %d and y is %d\n",x,y);
    y++;
    return 0;
}
