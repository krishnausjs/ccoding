#include <stdio.h>
#include <conio.h>

int main() {
	int c, getch(void);	
	void ungetch(int);
	char *w = word;

	/*Read till you encounter space*/
	while(isspace(c=getch()));	

	if(c != EOF)
		*w++ = c;

	if(!isalpha(c)) {
		
	}
	
}

