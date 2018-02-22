#include <stdio.h>

int subSumArray(int arr[], int n, int sum)
{
    int cur_sum=arr[0];
    int i=0,k=0;
    int start = 0;

    //From 0 to n elements 
    for(i=0; i<n; i++)
    {
        //Starting from first element, check if each element is greater than sum element
        //If so, deduct that particular element from cur_sum(total)
        //start is to keep track of the elements we deducted from cur_sum (total)
        //while((cur_sum > sum)&&(start < i-1))
        while(cur_sum > sum)
        {
            cur_sum = cur_sum - arr[start];
            start++;
        }

        if(cur_sum == sum)
        {
            printf("Sum found between indexes %d and %d\n",start,i);
            printf("\n");
            for(k=start; k<i; k++)
                printf("%d\t",arr[k]);
            printf("\n");
            return 1;
        }

        cur_sum = cur_sum + arr[i];
        printf("At %d, Value of cur_sum is %d\n",i,cur_sum);
    }
    printf("No subarray found\n");
    return 0;
}

int main()
{
    //int arr[] = {15,2,4,8,9,5,10,23};
    int arr[] = {1,2,3,4,2,1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 6;
    subSumArray(arr,n,sum);
    return 0;
}
