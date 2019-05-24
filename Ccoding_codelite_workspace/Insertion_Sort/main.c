#include <stdio.h>
void printArray(int arr[], int arrSize)
{
    int i = 0;
    for(i = 0; i < arrSize; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int arrSize)
{
    int i , j;
    int key;
    
    for(j = 1; j < arrSize; j++)
    {
        key = arr[j];
        i = j - 1;
        while(i >= 0 && arr[i] > key)
        {
            arr[i+1] = arr[i];
            i = i - 1;
        }
        arr[i+1] = key;
    }
    printArray(arr,arrSize);
}

int main(int argc, char **argv)
{
	int arr[] = {5, 3, 2, 1};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,arrSize);
    insertionSort(arr,arrSize);
	return 0;
}
