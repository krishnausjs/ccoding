#include <stdio.h>
#include <time.h>

int fib(int n)
{
    int i;
    int lookup[n+1];
    lookup[0]=0;    
    lookup[1]=1;    
    for(i=2; i<=n; i++)
        lookup[i] = lookup[i-1]+lookup[i-2]; 
    return lookup[n];
}
int main()
{
    int n=9;
    int begin,end;
    double time_spent;
    begin = clock();
    printf("Fibonacci of %d is %d\n",n,fib(n));
    end = clock();
    time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("Time spent is %lf\n",time_spent);
    return 0;	
}
