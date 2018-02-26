#include <stdio.h>

void printArray(int arr[], int size);

int gcd(int a, int b);

void leftRotate(int arr[], int d, int n)
{
    int i=0,j=0,k=0;
    int temp;

    printf("gcd of %d and %d is %d\n",d,n,gcd(d,n));
    //GCD divides the array into gcd(d,n) subarrays
    //Run loop from 0 to gcd(d,n)
    for(i=0; i<gcd(d,n); i++)
    {
        //Start from from element
        temp = arr[i];
        //This is inner counter
        j=i;
        //For each set till i equals to k
        //Where k jumps d times in while loop 
        while(1)
        {
            printf("i = %d , j = %d, k=%d and d=%d\n",i,j,k,d);
            //Shifting from dth element in increments of j
            k = j + d;

            //If k is greater than n, we need to rotate k
            if(k >= n)
                k = k % n;
            //When you execute above instruction, there is a chance i == k
            if(i == k)
                break;
             
            printf("Moving arr[%d] ==to==> arr[%d]\n",k,j);
            //Finally, store kth element to subarrary
            arr[j] = arr[k];
            //Go for next subarray
            j = k;
        }
        printf("\n");
        arr[j] = temp;
    }
}

void printArray(int arr[], int size)
{
    int i=0;
    printf("Array contents are \n");
    for(i=0; i<size; i++)
        printf("%d\t",arr[i]);
    printf("\n");
}

int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return(gcd(b,a%b));
}

int main()
{
    int arr[] = {1,2,3,4,5};
    leftRotate(arr,2,5);
    printArray(arr,5);
    return 0;
}


