#include <stdio.h>

// This function just reverses a word character by character
// Input args are pointer to beginning of word and pointer to end of the word
void reverse_current_word(char *begin, char *end)
{
    char *temp;
    while(begin < end)
    {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

//This function reveses the string.
void reverse_sentence(char *str, int len)
{
    //Take two pointers and assign them to beginning of the sentence
    char *word_begin = str;
    //Lets consider this as a pointer to current word. 
    char *temp = str;
    
    //Till we have a valid letter
    while(*temp)
    {
        //We have already read one letter so go ahead and increment temp
        //Check if current tem
        temp++;
        //End case
        if(*temp == '\0')
        {
            reverse_current_word(word_begin, temp-1);
        }
        else if(*temp == ' ')
        {
            reverse_current_word(word_begin, temp-1);
            word_begin = temp+1;
        }
        //temp++;
    }
    //Revese current word with start and end address of current word.
    reverse_current_word(str,temp-1);
}
int main(int argc, char **argv)
{
	char str[30] = "I love programming very much";
    int str_len = strlen(str);
    reverse_sentence(str, str_len);
    printf("Reversed string is %s\n",str);
	return 0;
}
