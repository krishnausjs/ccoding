#include <stdio.h>

int convert0To5Rec(int num)
{
    if(num == 0)
        return 0;

    int digit = num%10;

    printf("Value of num is %d and %d\n",num,digit);
    if(digit == 0) 
        digit = 5;
    //printf("Value of convert0To5Rec is %d\n",convert0To5Rec(num/10)+digit);
    return convert0To5Rec(num/10) * 10 + digit;
}

int convert0To5(int num)
{
    if(num == 0)
        return 5;
    else
        return convert0To5Rec(num);
}

int main()
{
    int num=10120;
    printf("%d\n",convert0To5(num));
    return 0;
}
