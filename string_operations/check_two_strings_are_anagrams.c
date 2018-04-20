#include <stdio.h>
#include <stdbool.h>

#define NO_OF_CHARS 256

bool areAnagrams(char *str1, char *str2)
{
    int count1[NO_OF_CHARS] = {0};
    int count2[NO_OF_CHARS] = {0};
    int i;

    for(i=0; str1[i] && str2[i]; i++)
    {
        count1[str1[i]]++;
        count2[str2[i]]++;
    }

    printf("Value of i is %d str1[i] is %c and str2[i] is %c\n",i,str1[i],str2[i]);
    if(str1[i] || str2[i])
    {
        printf("Either or both strings didnt reach the end\n");
        return false;
    }

    for(i=0; i<NO_OF_CHARS; i++)
        if(count1[i] != count2[i])
            return false;

    return true;
}

int main()
{
    char str1[] = "geeksforgeeks";
    char str2[] = "forgeeksgeeksis";
    if( areAnagrams(str1,str2))
        printf("Two strings are anagrams of each other\n");
    else
        printf("Two strings are not anagrams of each other\n");
    return 0;
}
