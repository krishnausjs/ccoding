#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(char *dest, char *src)
{
    int temp;
    temp = *src;
    *src = *dest;
    *dest = temp;
}

bool is_vowel(char c)
{
    bool ret = false;
    switch(c)
    {
        case 'a': 
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            ret = true;
            break;
        default:
            break;
    }
    return ret;
}

void reverse_vowels(char *str, unsigned int len)
{
    int i,j;
    i = 0;
    j = len-1;
   while(i < j) 
    {
        if(is_vowel(str[i]) && is_vowel(str[j]))
        {
            swap(&str[i++],&str[j--]);
        }
        else
        {
            if(! is_vowel(str[i])) i++;
            if(!is_vowel(str[j]))  j--;
        }
    }
    printf("After reversing vowel, string %s\n",str);
}

int main(int argc, char **argv)
{
	char str[20]="hello";
    unsigned int len =  strlen((const char *)str);
    printf("Length of string %s is %d\n",str,len);
    reverse_vowels(str,len);
	return 0;
}