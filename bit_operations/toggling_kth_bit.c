#include <stdio.h>

#define TOGGLE_BIT(num,x) (num ^=(1<<(x-1)))

unsigned int toggle_bit(unsigned int num, int x)
{
	return (num ^= (1UL<<(x-1)));
}

int main()
{
	unsigned int num = 5;
	int k = 1;

	printf("%d ",toggle_bit(num,k));
	printf("%d \n",TOGGLE_BIT(num,k));
	return 0;
}
