#include <stdio.h>

static inline int get_int_order(unsigned long val)
{
    int order=0;
    if(val){
        while((val=(val >>1)))
            order++;            
                            // Here order is highest bit
        if(val &(val-1))    
            order++;        // But more than one bit set
        }
    return order;
}

int main()
{
    unsigned long val=64;
    printf("\n Get order value is %d\n",get_int_order(val));
    return 0;
}
