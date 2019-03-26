#include <stdio.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char **argv)
{
    int len;    /* current line length */
    int max;  /* Maximum length seen so far"*/
    
    char line[MAX_LINE_LENGTH];
    
    int max = 0;
    FILE *f2 = fopen("meta_data.txt", "rw");
    if(f2 != NULL)
    {
        printf("Printing the file line by line\n")
        while(len = getline(line, MAX_LINE_LENGHT)) > 0)
        {
            printf("%s",line);
        }
        fclose(f2);
    }
    else
    {
            printf("F2 is NULL\n");
            
    }
 	return 0;
}
