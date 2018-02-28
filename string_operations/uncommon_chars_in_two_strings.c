#include <stdio.h>
#define ASCII_CHAR_SIZE 26
findUncommonChars(char *str1,char *str2)
{
    int ascii_table1[ASCII_CHAR_SIZE]={0};
    int i;

    while(*str1 != '\0')
    {
        printf("Value of *str1 is %c storing at %d \n",*str1,(*str1-'a'));
        //Store 1 for each character in the string
        ascii_table1[*str1 - 'a'] = 1;
        *str1++;
    }

    printf("\n");
    while(*str2 != '\0')
    {
        printf("Value of *str2 is %c storing at %d\n",*str2,(*str2-'a'));
        // There is a chance that duplicate character may slip out without
        // the later condition in below instruction. So make sure we consider it
        if((ascii_table1[*str2 - 'a'] == 1) ||(ascii_table1[*str2 - 'a'] == -1))
        {
            //If its common character between str1 and str2, make it -1 in table1
            ascii_table1[*str2 - 'a'] = -1;
        }
        else
        {
            printf("*str2 char %c is unique\n",*str2);
            //If its  unique in str2, make it 2
            ascii_table1[*str2 - 'a'] = 2;
        }
        *str2++;
    }
    //Now , entries -1 in ascii_table show the common characters
    //entries 1 in ascii_table show the unique characters in str1
    //entries 2 in ascii_table show the unique characters in str2
    for(i=0; i<ASCII_CHAR_SIZE; i++)
    {
       // if((ascii_table1[i] == 1) || (ascii_table2[i] == 2))
        if((ascii_table1[i] == 1) || (ascii_table1[i] == 2))
                    printf("%c ",i+'a');
    }
    printf("\n");
}
int main()
{
    char str1[] = "characters";
    char str2[] = "alphabets";

    findUncommonChars(str1,str2);
    return 0;
}
