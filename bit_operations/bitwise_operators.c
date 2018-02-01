#include <stdio.h>

int main()
{

    int data=0xbcadFFAE;
 
    printf("\n data >> 24 is 0x%x\n",((data & 0xFF000000) >> 24));
    printf("\n data >> 8 is 0x%x\n",((data & 0x00FF0000) >> 8));
    data = ((data & 0xFF000000) >> 24) | 
	   ((data & 0x00FF0000) >> 8)  |
	   ((data & 0x0000FF00) << 8)  |
	   ((data & 0x000000FF) << 24);

    printf("\n Value of data is 0x%x\n",data);
    return 0;
}
