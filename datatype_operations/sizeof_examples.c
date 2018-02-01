#include<stdio.h>
#define INVALID_HEAP_ID     ((int)-1)
int main()
{
    double num=5.2;
    int  var=150000;
    printf("%d\t",sizeof(!num));
    printf("%d \t",sizeof(var=num+15/2));
    printf("%d\n",var);
    printf("value of macro is %d\n",INVALID_HEAP_ID);
    return 0;
}
