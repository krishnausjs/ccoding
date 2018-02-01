#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define DELIM " " 
int main(void)
{
    char input[100];
    int len = 0;
    char *token = NULL;
    
    sprintf(input," APP Crash issue investigation %s:%d\n",__FUNCTION__,__LINE__); 
    token = strtok(input, DELIM);
    while (token != NULL)
    {
       printf("%s ",token);
       printf("%d ",len++);
       token = strtok(NULL, DELIM);
    }
    printf("\n");
    return EXIT_SUCCESS;
}
