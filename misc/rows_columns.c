#include <stdio.h>

int main()
{
    int i=0;
    unsigned char buffer[400];
    for(i=0;i<400;i++)
    {
        buffer[i]=i;
    }
						
    for(i=0; i<400;i++)
    {
        printf("0x%02x ",buffer[i]);
	if(!((i+1)%8))
	{
	    printf(" ");
	}
	if(!((i+1)%16))
	{
	    printf("\n");
	}
    }
    printf("\n");
    return 0;     
}
