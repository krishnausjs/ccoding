#include <stdio.h>
#define VALID_CHUNK_LIST_ID         ((0x5AFE)<<16)
#define VALID_CHUNK_LIST_ID_1         ((0x01)<<16)

int main()
{
    unsigned long ret;
    unsigned long ret1;
    ret = VALID_CHUNK_LIST_ID;
    ret = VALID_CHUNK_LIST_ID_1;
    printf("Value of chunk list id is %x\n",ret);
    printf("Value of chunk list id is %x\n",ret1);
    return 0;
}
