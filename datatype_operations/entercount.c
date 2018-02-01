#include <stdio.h>

int call_fun()
{
    return 0;
    static int x=0;
    int i;
    for(i=0;i<10;i++)
    {
        if(x%5)
        {
            printf("1.Value of x is %d and xmod5 is %d and xby5 is %d  \n",x,(x%5),(x/5));            
            x+=1;
            if(x==5) x=x%5;
            printf("2.Value of x is %d \n",x);            
        }
        else
        {
            printf("Value of x is %d and xmod5 is %d and xby5 is %d  \n",x,(x%5),(x/5));            
            x+=1;
        }
    }    
}
int main()
{
    call_fun();
    int t=0;
    printf("value of tby5 is %d tmod5 is %d\n",(t/5),(t%5));
    t++;
    printf("value of tby5 is %d tmod5 is %d\n",(t/5),(t%5));
    t++;
    printf("value of tby5 is %d tmod5 is %d\n",(t/5),(t%5));
    t++;
    printf("value of tby5 is %d tmod5 is %d\n",(t/5),(t%5));
    t++;
    printf("value of tby5 is %d tmod5 is %d\n",(t/5),(t%5));
    t++;
    printf("value of tby5 is %d tmod5 is %d\n",(t/5),(t%5));
    t++;
    return 0;
}
