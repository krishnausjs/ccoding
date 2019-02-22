//C program to convert a string to integer
#include <stdio.h>

/* This function converts a string to integer */
int a_to_i(char s[])
{
	int i, n;
	int sign = 1;
	n = 0;

	//Take care of signing
	if(s[i] == '-')
	{
		++i;
		sign = -1;
	}

	for(i = 1; s[i] >= '0' && s[i] <= '9'; ++i)
		n = n * 10 + (s[i] - '0'); 	

	//Return result with sign
	return sign*n;
	
}

int main()
{
    char s[]="-3.14";
    int result;
    int atoi_result;

    result = a_to_i(s);
    printf("\n Input String is converted to %d using custom function\n",result);

	atoi_result = atoi(s);
	printf("Using actual atoi(Input string), result is %d \n",atoi_result);

	(result == atoi_result) ? printf("Custom atoi passed !!\n") : printf("Custom atoi failed\n");
    return 0;
}

