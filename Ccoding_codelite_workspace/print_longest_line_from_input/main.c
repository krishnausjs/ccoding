//C Program to print longest line from input

//Standard headers required
#include <stdio.h>

#define MAXLINE 1000

int getLine(char s[], int limit);
void copy(char to[], char from[]);

// 
int main(int argc, char **argv)
{
    int len = 0;
    int max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];
    
    while((len = getLine(line, MAXLINE)) > 0) {
        if( len > max) {
            max = len;
            copy(longest, line);
        }        
    }
    if(max > 0) 
        printf("%s\n", longest);
        
    getchar();
    return 0;
}

int getLine(char s[], int limit) {
    int i = 0;
    
    //Read character by character till end of the line
    for( i = 0; (i < limit - 1) && ( (c = getchar()) != EOF && (c != '\n')) && (); ++i)
        s[i] = c;
        
    if(s[i] == '\n')
        s[++i] = c;
        
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    while((to[i] == from[i]) != '\0')
        ++i;
}