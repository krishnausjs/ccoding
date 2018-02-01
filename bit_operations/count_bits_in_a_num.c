#include <stdio.h>

unsigned int count_bits(unsigned int num) {
    int count=0;
    int num_of_bits=sizeof(num)*8;
    printf("\n Value of num_of_bits is %d\n",num_of_bits);
    int i=0;
    while(num)
    {
    	count+=(num&1); 
        num=num>>1;
    }
    printf("\n Value of count is %d\n",count);
    return count;
}

int main()
{
   unsigned int num=20;
   printf("\n Value of i is %d\n",count_bits(num));
   return 0; 
}
