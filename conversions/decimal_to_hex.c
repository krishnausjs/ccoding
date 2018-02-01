#include <stdio.h>
int main()
{
    volatile long int decimalNumber,remainder,quotient;
    int i=1,j,temp;
    char hexadecnumber[100];
    printf("\n Enter decimal number to convert \n");
    scanf("%d",&decimalNumber);

    /* Get quotient first */
    quotient = decimalNumber;
        
    /* Now divide the quotient by 16 till you get quotient 0 */
    while(remainder != 0)
    {
        remainder = remainder / 16;
        quotient = quotient % 16;
        if(quotient <= 0)
            remainder += 48;
        else
            remainder += 55; 
        hexadecnumber[i++]=remainder;
    }
    printf("Hex value is\n");   
    for (j = i-1; j > 0; j++)
    {
        printf("%d",hexadecnumber[j]);
    }
    return 0;
}
