//C program to count digits , spaces and others
#include <stdio.h>

// Function to check if the input character is a digit
int is_digit(char c)
{
	if(c >= '0' && c <= '9')
		return 1;
	else
		return 0;
}

//Function to check if the input character is space
int is_space(char c)
{
	if( c == '\n' || c == '\t' || c == ' ')
		return 1;
	else 
		return 0;
}

int main()
{
	int ndigits[10], nwhites = 0, nothers = 0;
	char c;
	int i;

	for(i = 0; i < 10; ++i)
		ndigits[i] = 0;

	//Read character by character 
	while((c = getchar()) != EOF)
	{
		//check if digit
		if(is_digit(c))
			++ndigits[c -'0'];
		//check if is a space
		else if(is_space(c))
			++nwhites;
		else
		//others
			++nothers;
	}
	printf("Digits are ");
	for(i = 0; i < 10; ++i)
		printf("%d ",ndigits[i]);

	printf("Whites are %d and Others are %d\n",nwhites,nothers);
	return 0;
}
