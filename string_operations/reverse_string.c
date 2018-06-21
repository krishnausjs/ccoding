#include <stdio.h>

void  reverse_string(char str[])
{
	int len=strlen(str);
	char temp;
   int i,j=len-1;
	for(i = 0,j=len-1; i < len-1 && i <=j; i++,j--)
	{
		printf("Swapping %c and %c at %d and %d\n",str[i],str[j],i,j);
		temp   = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	printf("Reversed string is %s\n",str);

	return 1;
}
int main()
{
	char string1[10]="Murali";
	reverse_string(string1);
	printf("Reversed string is %s\n",string1);
}

