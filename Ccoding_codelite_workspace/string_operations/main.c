#include <stdio.h>

#define MAX_LINE_LENGTH 100
#define STRING_REVERSAL 

int main()
{
    int len = 0;
    int max = 0;
    int line[MAX_LINE_LENGTH];
    int longest_line[MAX_LINE_LENGTH];
    
    while((len = get_a_line(line, MAX_LINE_LENGTH)) > 0)
    {
        if(len > max)
        {
            max = len;
            copy_a_line(longest_line, line);
        }
    }
    
    if(max > 0)
    {
        printf("Longest line is \n");
        printf("%s\n",longest_line);
    }
    
    return 0;
}

int get_a_line(char s[], int lim)
{
    int i = 0;
    char c;
    // We need to read char by char
    // we need to read till lim or till we encounter \n
    for(i = 0; (i < lim) && ((c = getchar()) != EOF) && (c != '\n'); i++)
        s[i] = c;
        
    // Now we have  read a line. Dont forget to include the new line and end the string appropriately.
    if( c == '\n')
    {
        s[i] = '\n';
        ++i;
    }
    
    s[i]='\0';
    
    return i;
}

int copy_a_line(char to[], char from[])
{
    int i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}