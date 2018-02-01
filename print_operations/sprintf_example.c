#include <stdio.h>
#include <math.h>

int buffer[1000];
int main()
{
    char str[80];

    sprintf(str, "Entered function");
    puts(str);
    int bufflen; 
    int i;

    //strcpy ( buffer, "This is buffer");
    sprintf(buffer,"This is buffer","%s");
    bufflen = (unsigned short) strlen ( buffer );
    printf("Buffer length is %d\n",bufflen);
    printf ( "%s", "Buffer -->" );

    for ( i = 0; i < bufflen; i++ )
    {
//         putc( isprint(buffer[i]) ? buffer[i] : '.' , stdout );
    }

    printf ( "%s", "<--\n\n" );

   return(0);
}
