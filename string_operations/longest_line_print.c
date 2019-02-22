// C program to read n number of lines and print the longest line.
// This is from K&R Chapter 1 Section 1.9

// This program can be done using three functions.
// 1. Main 2.get_a_line 3. copy_a_line
#include <stdio.h>

//Fixing max line to 100
#define MAX_LINE_LENGTH 100

//This is the actual main function
int main()
{
	//Declar variables and initialize them
    int len = 0;
    int max = 0;
	
    int line[MAX_LINE_LENGTH];
    int longest_line[MAX_LINE_LENGTH];
    
	//Read a line, each line has a max limit
    while((len = get_a_line(line, MAX_LINE_LENGTH)) > 0)
    {
		//If current line length is more than max line
        if(len > max)
        {
			//Update max 
            max = len;
			//Take a backup of longest line into temporary longest_line buffer
            copy_a_line(longest_line, line);
        }
    }
    
	//Print longest line only if max is postitive.
    if(max > 0)
    {
        printf("\nLongest line is :  ");
        printf("%s\n",longest_line);
    }
    
    return 0;
}

/* This function reads a line given input buffer and string limit */
int get_a_line(char s[], int lim)
{
	//Declare variables and initialize them
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
    
	//End string with '\0'. This is very important.
    s[i]='\0';
    
    return i;
}

/* This function copies a line, character by character. */
int copy_a_line(char to[], char from[])
{
    int i = 0;
	//Copy character by character 
    while((to[i] = from[i]) != '\0')
        ++i;
}
