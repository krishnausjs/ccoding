#include <stdio.h>

#define VALUE_1 0x00000002
#define VALUE_2 0x00000004

int main()
{
    char state;
    state=0;
    int status=0;
    printf("value of state is %d\n",state);
    state|=VALUE_1;
    if(state&VALUE_2)
    {
        printf("chaing state value %d\n",state);
        state|=VALUE_2;
    }
    for(state=0;state<10;state++)
    {
        status^=1;
        printf("\n status is %d\n",status);
    } 
    printf("value of state is %d\n",state);
    return 0;
}
