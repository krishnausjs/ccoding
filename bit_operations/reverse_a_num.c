#include <stdio.h>
unsigned int reverse_a_num(int num)
{
    unsigned int num_of_bits=sizeof(num)*8;
    unsigned int temp;
    unsigned int reverse_num=0;
    unsigned int i=0;
    for(i=0;i<num_of_bits;i++)
    { 
        if(num&(1<<i))
        reverse_num |= ((1<<(num_of_bits-1))-i);
    }
    return reverse_num;
}
int main()
{
    unsigned int n=2;
    unsigned int num=0;
    num=reverse_a_num(n);
    printf("\nReverse of a number is %u\n",num);
    return 0;
}

