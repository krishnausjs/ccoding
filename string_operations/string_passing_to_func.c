#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEMP_DELIM "$"

int printf_wrapper(char *input)
{
	char *temp_token=NULL;
   printf("\n Entered \n");
   temp_token = strtok(input, TEMP_DELIM);
   while (temp_token != NULL)
   {
      printf("%s \n",temp_token);
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
	 char temp_buff2[] = {0};
	 printf("size of temp_buff is %d and size of temp_buff2 is %d\n",sizeof(temp_buff),sizeof(temp_buff2));

	 temp_buff2[0] = 'a';
	 temp_buff2[1] = 'e';
	 temp_buff2[2140] = 'i';
		
	 printf("Value of temp_buff2 is %s\n",temp_buff2);
    sprintf(temp_buff,"This is a $string %s:%d$ This is second line$ This is third line $",__FUNCTION__,__LINE__);
    function1(temp_buff,"ENTER");
    return 0;
}
