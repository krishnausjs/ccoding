#include <stdio.h>
#include <string.h>
unsigned int bcd_to_hex(unsigned int bcd)
{
        char temp_buff[20];
        unsigned int hex;
        memset(temp_buff,0x00,20);
        sprintf(temp_buff,"%x",bcd);
        sscanf(temp_buff,"%d",&hex);
        return hex;
}
unsigned int hex_to_bcd(unsigned int hex)
{
        char temp_buff[20];
		unsigned int bcd;
        memset(temp_buff,0x00,20);
        
        sprintf(temp_buff,"%d",hex);
        sscanf(temp_buff,"%x",&bcd);
        return bcd;
}
int main()
{
    unsigned int bcd;
    unsigned int hex;
    bcd=9;
    hex=12;
    printf("Value of hex to bcd is %d\n",hex_to_bcd(hex));
    printf("Value of bcd to hex is %d\n",bcd_to_hex(bcd));
    
    return 0;
}
