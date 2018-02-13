#include <stdio.h>
void remove_stdout_line()
{
        sleep(1);
        //remove line. Prints above line and remove it after n seconds. Good for analysis
        fputs("\033[A\033[2K",stdout);
        rewind(stdout);
}

int lis(int arr[], int n)
{
   int i,j,max;
   int LIS[n+1];

   for(i=0; i<n; i++)
        LIS[i]=1;

   printf("Arr elements are ..\n");
   for(i=0;i<n;i++)
       printf("%d\t",arr[i]);
 
   printf("\nLIS elements are ..\n");
   for(i=0;i<n;i++)
       printf("%d\t",LIS[i]);

    for(i=1; i<n; i++)
    {
        for(j=0;j<i;j++)
        {
            printf("\nValue of i is %d and j is %d , arr[i] is %d and arr[j] is %d\n",i,j,arr[i],arr[j]);
            remove_stdout_line();
            if((arr[i]>arr[j]) && (LIS[i] < LIS[j]+1))
            {
                LIS[i] = LIS[j]+1;
                printf("Updated LIS value at %d is %d\n",i,LIS[i]);
            }
        }
    }

   printf("\nUpdated LIS elements are ..\n");
   for(i=0;i<n;i++)
       printf("%d\t",LIS[i]);

   max=LIS[0];
   for(i=0;i<n;i++)
       if(max < LIS[i])
           max=LIS[i];

   return max;
}

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int lis_value = 0;
    int size_of_array = sizeof(arr)/sizeof(arr[0]);
    printf("Value of size of array is %d\n",size_of_array);
    lis_value = lis(arr,size_of_array);
    printf("\n Value of LIS of given array is %d\n",lis_value);
    return 0;
}
