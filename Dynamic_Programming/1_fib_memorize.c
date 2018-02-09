#include <stdio.h>
#include <time.h>

#define MAX 100
#define NIL -1

int lookup[MAX];

void initialize()
{
    int i=0;
    for(i=0; i<MAX; i++)
        lookup[i] = NIL;
}

int fib(int n)
{
    if(lookup[n] == NIL)
    {
	if(n <= 1)
	    lookup[n] = n;
	else
	    lookup[n] = fib(n-1) + fib(n-2);
    }
    return lookup[n];    
}

int main()
{
    clock_t begin,end;
    double time_spent;
    int n = 9;
    begin = clock();
    initialize(); 
    printf("\n Fibnocci of 9 is %d\n",fib(9));	
    end = clock();
    time_spent = (double) (end-begin)/CLOCKS_PER_SEC;
    printf("Time spent is %lf\n",time_spent);
    return 0;
}

