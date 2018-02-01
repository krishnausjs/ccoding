#include <stdio.h>
#include <malloc.h>
#define NEW_BUF_SIZE 4096
int main()
{
    char *buf;
    buf=(char*)malloc(NEW_BUF_SIZE);
    int temp_count=0;
    int total_count=0;

    memset(buf,0x00,NEW_BUF_SIZE);
    memset(buf,0x38,NEW_BUF_SIZE);
    temp_count=128;
    do
    {   
         Print_Heap_content(buf,temp_count);
         total_count+=temp_count;
    }while(total_count <= NEW_BUF_SIZE);
    return 0;
}

int Print_Heap_content(char *buffer,int count)
{
    int i=0;
    printf("\n");
    for(i=0;i<count;i++)
    {
        printf("0x%x ",buffer[i]);
    }
    printf("\n");
    sleep(5);
    return 0;
}
