#include <stdio.h>
#if 0
static inline void loadBar(int x, int n, int r, int w)
{
    // Only update r times.
    if ( x % (n/r +1) != 0 ) return;
 
    // Calculuate the ratio of complete-to-incomplete.
    float ratio = x/(float)n;
    int   c     = ratio * w;
 
    // Show the percentage complete.
    printf("%3d%% [", (int)(ratio*100) );
 
    // Show the load bar.
    for (x=0; x<c; x++)
       printf("=");
 
    for (x=c; x<w; x++)
       printf(" ");
 
    // ANSI Control codes to go back to the
    // previous line and clear it.
    //printf("]\n\033[F\033[J");
    printf("]\n33[1A33[2K");
}
#else
static inline void loadBar(int x, int n, int r, int w)
{
    // Only update r times.
    if ( x % (n/r) != 0 ) return;
 
    // Calculuate the ratio of complete-to-incomplete.
    float ratio = x/(float)n;
    int   c     = ratio * w;
 
    // Show the percentage complete.
    printf("%3d%%[", (int)(ratio*100));
 
    // Show the load bar.
    for (x=0; x<c; x++)
       printf("=");
 
    for (x=c; x<w; x++)
       printf(" ");
 
    // ANSI Control codes to go back to the
    // previous line and clear it.
    // printf("]\n33[F33[J");
	printf("\r"); // Move to the first column
	fflush(stdout);
}
#endif

int main()
{
    int i;
    for(i=0;i<100;i++)
    {
	loadBar(i,1,1,1);  
    }
    return 0;
}
