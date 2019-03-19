#include <stdio.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int getNumberOfBits(int num)
{
    unsigned int c = 0;
    while(num)
    {
        num &= (num - 1);
        ++c;
    }
  // printf("Value of c is %d\n",c);
    return c;
}

int* countBits(int num, int* returnSize) {
    int i = 0;
    returnSize = (int*)malloc(sizeof(num+1));
    for(i = 0; i <= num; i++)
    {
        *(returnSize+i) = getNumberOfBits(i);
       printf("returnSize is %d\n",returnSize[i]);
        
    }
    return 0;
}

int main(int argc, char **argv)
{
    int i,num = 5;
    int  *ptrArray;
    countBits(num, ptrArray);
    for(i = 0; i < num; i++)
    {
        printf("%d ",*(ptrArray+i));
    }
    free(ptrArray);
	return 0;
}
