#include <stdio.h>
#include <stdlib.h>

#define TEMP_DELIM " \n"

int printf_wrapper(char *input)
{
	char *temp_token=NULL;
    printf("\n Entered \n");
    temp_token = strtok(input, TEMP_DELIM);
    while (temp_token != NULL)
    {
       printf("%s ",temp_token);
       temp_token = strtok(NULL, TEMP_DELIM);
    }
    printf("\n");
}

int function1(char *temp_ptr,char *etype)
{
    printf_wrapper(temp_ptr);
    //printf("\n Value of temp_buff is %s and etype is %s\n",puts(temp_ptr),puts(etype));
    return 0;
}
int main()
{
    char temp_buff[2140];
    sprintf(temp_buff,"This is a string %s:%d\n",__FUNCTION__,__LINE__);
    function1(temp_buff,"ENTER");
    return 0;
}
