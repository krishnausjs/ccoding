#include <stdio.h>
//#define METHOD1
//#define METHOD2
#define METHOD3

#ifdef METHOD1
void swap(char *dest, char *src)
{
    int temp;
    temp = *src;
    *src = *dest;
    *dest = temp;
}
void reverse_string(char *str, int len)
{
    int head, tail, temp;
    head = 0;
    tail = len-1;
    printf("Value of str is %s\n",str);
    while(head <= tail)
    {
        printf("Moving %c  %c\n",*(str+head),*(str+tail));
        //swap(&str[head],&str[tail]);
        //swap((str+head),(str+tail));
        //head++;
        //tail--;
        swap(&(str[head++]), &(str[tail--]));
    }
    
    printf("Reverse String is %s\n",str);
}
#endif

#ifdef METHOD2
void rev_string(unsigned char *str, unsigned int len)
{
	int i;
	int j;
	unsigned char a;
	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		a = str[i];
		str[i] = str[j];
		str[j] = a;
	}
}
#endif


#ifdef METHOD3
void reverse_string(char* s, int sSize) {
    int i,j;
    int temp;
    for(i = 0,  j = sSize-1;  i < j;  i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    printf("[");
    for(i = 0; i < sSize; i++)
    {
        printf("\"");
        printf("%c",s[i]);
        printf("\"");
        if(i < sSize-1)
            printf(",");
    }
    printf("]");
    printf("\n");
}
#endif

int main(int argc, char **argv)
{
	char str[20]="Hello";
    unsigned int len =  strlen((const char *)str);
    printf("Length of string %s is %d",str,len);
    reverse_string(str,len);
	return 0;
}
