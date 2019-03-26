#include <stdio.h>

int swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int min(int x, int y)
{
    if(x<y)
        return x;
    else
        return y;
}
int reverse(int arr[], int n, int k)
{
    int i=0;
    int left, right;
    printf("Value of n is %d\n",n);
    for(i=0; i<n; i+=k)
    {
        left = i;
        right = min(i+k-1,n-1);
        //right = i+k-1;
        printf("Value of i = %d,  k = %d\n",i,k);
        printf("Value of left is %d and right is %d\n",left, right);
        while(left < right)
            swap(&arr[left++],&arr[right--]);
    }

    printf("Array contents are \n");
    for(i=0; i<n; i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 10;
    reverse(arr,n,k);
    return 0;
}
