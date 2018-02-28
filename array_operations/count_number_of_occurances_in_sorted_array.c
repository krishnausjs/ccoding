#include <stdio.h>

int count(int arr[],int x, int n)
{
    int i,j;

    i = first(arr, 0, n-1, x, n);
    printf("Value of i is %d\n",i);
    if(i == -1)
        return i;

    j = last(arr, i, n-1, x , n);
    printf("Value of j is %d\n",j);

    return j-i+1;
}

int first(int arr[], int low, int high, int x, int n)
{
    if(high > low)
    {
        int mid = low+(high-low)/2;
        //If mid is 0 , it means there is only one element
        //x>arr[mid-1]  making sure that x is more than arr[mid-1]
        //Suppose x is 2, arr[mid-1] should be 1, since the array
        //is already sorted, we consdier that x > arr[mid-1] to check
        //if x is the first element. Apart from this, we also need to check
        //if arr[mid] is equal to x. This is mandatory
        if((mid == 0) || (x>arr[mid-1] && arr[mid] == x))
            return mid;
        //If x > arr[mid], then x is in second half
        else if(x > arr[mid])
            return first(arr, (mid+1), high, x, n);
        //else x is in first half
        else
            return first(arr, low, (mid-1), x, n);
    }
    return -1; 
}

int last(int arr[], int low, int high, int x, int n)
{
    if(high >= low)
    {
        int mid = (low+high)/2;
        //We check if there are no elements after mid by checking mid==n-1
        //Also we check if arr[mid+1] > x , to make sure that we have reached
        //the end. Say we have 1,2,2,2,3,3,3,3. If we want to get last occurance of 2 
        //which is at index 3, we check if 2<arr[4] && arr[3] == 2 which is true.
        //This is a boundry check condition which is quite useful
        if( (mid == n-1) || (x < arr[mid+1]) && arr[mid] == x )
            return mid;
        //Does x fall in first half ?
        else if(x < arr[mid])
            return last(arr,low, (mid-1), x, n);
        //If x fall in second half
        else
            return last(arr, (mid+1), high, x, n);
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,2,3,3,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 3;
    int c = count(arr, x, n);
    printf("%d occurs %d times\n",x,c);
    return 0;
}
