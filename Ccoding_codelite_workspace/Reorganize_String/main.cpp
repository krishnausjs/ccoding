/* Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:
Input: S = "aab"
Output: "aba"

Example 2:
Input: S = "aaab"
Output: " "
Note:  S will consist of lowercase letters and have length in range [1, 500].
 */
 
#include <stdio.h>
#include <string.h>

int Rearrange_string(char str[]);
void swap_string(char *ch1, char *ch2)
{
    int temp;
    temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
}

int main()
{
    char str[20] = "aab";
    char *sPtr;
    int retVal = 0;
    
    retVal = Rearrange_string(&str[0]);
    printf("Return value is %d\n",retVal);
    return 0;
}

int Rearrange_string(char *str) {
    int len = strlen(str);
    printf("Value of strlen is %d\n",len);
    
    int i=0;
    char *temp;
    char empString[10] = {'0'} ;
    
    for(i=0; i<len; i++) 
    {
        if(str[i] == str[i+1]) 
        {
            swap_string(&str[i],&str[i+1]);
        }
    }
    
    for(i = 0; i < len;  i++)
    {
        if(str[i] == str[i+1]) 
            return (int)empString;
    }
    return 0;
}