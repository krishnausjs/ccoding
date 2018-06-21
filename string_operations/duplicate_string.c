#include <stdio.h>

//Given a line find duplicate words in it
int find_number_of_words(char line[])
{
    int count=0;
	 while(*line)
	 {
        if(line != '\0')
        {
            printf("%c",*line);			
		      count++;	
        }
		  line++;
    }
    printf("\n");
    return count;
}


int main()
{
	 char line_one[100]="This is example";
    int count_words=find_number_of_words(line_one);

    
    printf("Number of words is %d\n",count_words); 
    return 0;
}
