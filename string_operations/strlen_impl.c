//C program to implement strlen
#include <stdio.h>
#include <string.h>

/* Custom function to return string length */
int string_len(char str[])
{
	int i =0;
	//Till we encouter end of the string count the chars
	while(str[i] != '\0')
		++i;
	return i;
}

int main()
{
	char str[20] = "Hello";
	int result = string_len(str);
	int strlen_result = strlen(str);

	printf("String %s length using custom function is %d\n", str, result);
	printf("String %s length using strlen is %d\n",str, strlen_result);

	(result == strlen_result) ? printf("Custom strlen passed !!!\n"): printf("Custom strlen failed.\n");
	return 0;
}
