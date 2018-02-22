#include <stdio.h>

void printArray(int arr[], int size);

int gcd(int a, int b);

void leftRotate(int arr[], int d, int n)
{
    int i=0,j=0,k=0;
    int temp;

    for(i=0; i<gcd(d,n); i++)
    {
        temp = arr[i];
        j=i;
        while(1)
        {
            printf("i = %d , j = %d, k=%d\n",i,j,k);
            k = j + d;
            if(k >= n)
                k = k % n;
            if(i == k)
                break;

            arr[j] = arr[k];
            j = k;
        }
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
    int arr[] = {1,2,3,4,5,6,7};
    leftRotate(arr,2,7);
    printArray(arr,7);
    return 0;
}


