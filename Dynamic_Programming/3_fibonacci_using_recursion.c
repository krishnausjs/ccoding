#include <stdio.h>
#include <time.h>

int fib(int n) {
    if(n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

int main()
{
    int n=9;
    clock_t begin,end;
    double time_spent;
    begin = clock();
    printf("%d\n",fib(n));
    end = clock();

    time_spent = (double) (end - begin)/CLOCKS_PER_SEC;
    printf("\nTime taken %lf\n",time_spent);
    return 0;
}
