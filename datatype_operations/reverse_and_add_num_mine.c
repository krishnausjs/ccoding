#include <stdio.h>

int main()
{
    int rev=0,num=0,sum=0,rem=0;
    printf("\n Entere number please ...\n");
    scanf("%d",&num);
    while(num!=0)
    {
        rem=num%10;
        rev= (rev*10)+rem;
        sum=sum+(num%10);
        num=num/10;
    }
    printf("sum is %d and rev is %d\n",sum,rev);
    return 0;
}
