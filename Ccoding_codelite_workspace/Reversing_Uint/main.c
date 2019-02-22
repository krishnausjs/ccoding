#include <stdio.h>

int main(int argc, char **argv)
{
	unsigned int num, rev_num;
    unsigned int byte1, byte2, byte3, byte4;
    
    num = 0xabcdeeff;
    printf("We have 0x%x unsigned integer to reverse\n",num);
    byte1 =  ((num) & (~(0xFFFFFF00)));
    printf("Value of byte1 is 0x%x\n",byte1);
    byte2 =  ((num) & (~(0xFFFF00FF)));
    printf("Value of byte2 is 0x%x\n",byte2);
    byte3 =  ((num) & (~(0xFF00FFFF)));
    printf("Value of byte3 is 0x%x \n",byte3);
    byte4 =  ((num) & (~(0x00FFFFFF)));
    printf("Value of byte4 is 0x%x\n",byte4);
    rev_num = (byte1 << 24) |  (byte2 << 8)  |  (byte3 >> 8) | (byte4>>24);
    printf("Value of Reversed unsigned int is 0x%x\n",rev_num);
	return 0;
}
