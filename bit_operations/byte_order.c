#include <stdio.h>

static int get_int_order(unsigned int val);

int main()
{
    unsigned int x;
    int i;
    for(i=0;i<10;i++)
    printf("\n Value of order of i(%d) is %d\n",i,get_int_order(i));
    return 0;
}

static int get_int_order(unsigned int val)
{
    int order=0;
    if(val) 
     {
        printf("\nValue of val is %d and  val>>1 is %d\n",val,(val>>1));
        while((val=(val >>1)))
            order++;            
                            // Here order is highest bit
        if(val &(val-1))    
            order++;        // But more than one bit set
        }
    return order;
}
