#include <stdio.h>
#include <malloc.h>

int main()
{
    FILE *fp;
    int c;
    int n=0;
    char *aptr;
    char *ptr1;
    fp=fopen("writets.ts","w+");

    aptr=(char*)malloc(400);
    
    for(n=0;n<400;n++)
    {
        aptr[n]=n;
    }
#if 0
    do
    {
        c=fgetc(fp);
        printf("%c",c);
    }while(c!=EOF);
    fclose(fp);
#else
    for(n=0;n<300;n++)
    {
        ptr1=aptr;  
        fputc(*ptr1,fp);
        aptr++;
    }
#endif   
    free(aptr);
    fclose(fp);
    return 0;
}
