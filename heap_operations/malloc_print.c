#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __malloc malloc
#undef malloc
#define malloc( _size ) \ ({ printf( "%s: Calling malloc(%d) from line %d, filename: %s\n", __func__, _size, __LINE__, __FILE__ ); \   __malloc( _size ); })

int main( int argc, char *argv[] )
{
    void *p;

    p = malloc( 1024 );
    memset( p, 0, 1024 );
    printf( "p=%p\n", p );
    free(p);

    return 0;
}
