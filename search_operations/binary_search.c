#include <stdio.h>

int binarySearch(int arr[], int left, int right, int x)
{
    if(right >= left)
    {
        int mid = left + (right -left)/2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] > x)
            return binarySearch(arr,left,mid-1,x);
        else if(arr[mid] < x)
            return binarySearch(arr,mid+1,right,x);
    }
    return -1;
}

int main()
{
    int arr[] = {2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr,0,n,x);
    (result == -1) ? printf("Element not found \n"): printf("Element found at %d index\n",result);
    return 0;
}
