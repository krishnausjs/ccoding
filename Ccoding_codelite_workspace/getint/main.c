#include <stdio.h>
#include <conio.h>
#include <ctype.h>

/* Buffer for ungetch */
#define BUFSIZE 100 

/* Buffer for ungetchar*/
char buf[BUFSIZE];

/* next free position in buf */
int bufp = 0;

/* Get a character */
int getch(void) 
{
    int c = 0;
    if(bufp > 0) 
    {
        c = buf[--bufp];
    }
    else
    {
        c = getchar();
    }
    return c;
}

/* Push character back on input */
void ungetchar(int c)
{
    if(bufp > BUFSIZE)
        printf("Ungetchar : too many characters\n");
    else
        buf[bufp++] = c;
}
/* Get next integer from input into *pn*/
/* Input example : -4445959593 */
int getint(int *pn)
{
    int c = 0, sign;
    
    /*Skip white spaces*/
    while(isspace(c = getch()))  
        ;
    printf("Input is %c\n",c);
    /* Check if its not a number */
    if(!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetchar(c);
        return 0;
    }
    
    /* Check sign */
    sign = (c == '-') ? -1 : 1;

    /* If first character is + or - read the next character*/
    if( c == '+' || c == '-')
        c = getch();
       
    /* Now convert string to integer */ 
    for( *pn = 0; isdigit(c); c = getch())
        *pn = 10  *  *pn + (c - '0');
    
    /*Add back the sign */
    *pn *= sign;
    
    /* */
    if(c != EOF)
        ungetchar(c);
        
    return c;
}

int main(int argc, char **argv)
{
     int pn = 0;
     int ret = 0;
     int n = 3, i;
     for(i = 0; i < n; i++)
     {
        ret = getint(&i);
       printf("Value of ret is %d\n",ret);
     }
	return 0;
}
