#include <stdio.h>
//This program worked locally but failed when i tried to use it in leetcode.
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 typedef enum state_t {
    START,
    STOP,
    UNKNOWN
 } e_state;

 
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int i, j;
    e_state in_sub_array = UNKNOWN;
    *returnSize = 0;
    int *res;
    
    if(nums1Size > nums2Size)
    {
        res  = (int *)malloc(nums2Size *sizeof(int));
        //nums1 i small array. We need to search these elements in big array nums2
        j = 0;
        for(i = 0;  i < nums1Size;  i++)
        {
                for( ;j < nums2Size;  j++)
                {
                    //If both are equal break
                    if(nums1[i] == nums2[j])
                    {
                        //match found, go for the next element
                        in_sub_array = START;
                        res[*returnSize]= nums1[i];
                       (*returnSize)++;
                       j++;
                    }
                    else
                    {
                        if(in_sub_array == START)
                            in_sub_array = STOP;
                    }
                    break;
                }
                if(in_sub_array == STOP)
                    break;
        }
    }
    else
    {
        res = (int*)malloc(nums1Size*sizeof(int));

        j = 0;
        for(i = 0;  i < nums2Size;  i++)
        {
                for(   ; j < nums1Size;  j++)
                {
                     //If both are equal break
                    if(nums1[i] == nums2[j])
                    {
                        //match found, go for the next element
                        in_sub_array = START;
                        *(res + (*returnSize) ) = nums2[i];
                       (*returnSize)++;
                       j++;
                    }
                    else
                    {
                        if(in_sub_array == START)
                            in_sub_array = STOP;
                    }
                    break;
                }
                if(in_sub_array == STOP)
                    break;
        }
    }   
    return res;
}

int main(int argc, char **argv)
{
    int arr1[10], arr2[10];
    int arr1_size = 0, arr2_size = 0;
    int i, j, in, out;
    int return_size = 0;
    int *temp_size;
    
    printf("Enter array 1 size \n");
    scanf("%d",&arr1_size);
    
    printf("Enter array 1 elements \n");
    for(i = 0; i < arr1_size; i++)
        scanf("%d",&arr1[i]);
        
    printf("Enter array 2 size\n");
    scanf("%d",&arr2_size);
    
    printf("Enter array 2 elements\n");
    for(j = 0; j < arr2_size; j++)
        scanf("%d",&arr2[j]);
        
    temp_size = intersect(arr1, arr1_size, arr2, arr2_size, &return_size);
    
    printf("Intersection of array is ..\n");
    for(i = 0; i < return_size; i++)
        printf("%d ",*(temp_size+i));
    printf("\n");
    
    free(temp_size);
	return 0;
}
