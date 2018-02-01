#include <stdio.h>
int main()
{
    char arr[10]="Hello";
    char *p = &arr[0];
    while(++*p)
    {
        printf("%c",*p);
       // printf("%c",*++p);
       // printf("%c ",++(*p));
    }
    printf("\n");
    return 0;
}
