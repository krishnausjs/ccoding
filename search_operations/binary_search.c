//C Program to find a number using binary search
#include <stdio.h>

//For this program we mainly need two functions
//1.main() 2.binary_search()

/* This function uses recursion technique to find the key in the array*/
int binary_search(int arr[], int l, int r, int key)
{
	int mid = 0;
	if( r >= l)
	{
		//Calculate the mid. This formula is tweaked to avoid integer overflow
		mid = l + (r - l) / 2;
		
		//If key is found at mid return mid.		
		if( key == arr[mid] )
			return mid;
		//If key less than arr[mid] then it means in the first half. 
		//Input here breaks down to half
		else if ( key < arr[mid] )
			return binary_search(arr, l, mid-1, key);
		else 
		//If key is greater than arr[mid] it falls in the second half.
		//Input here breaks down to half
			return binary_search(arr, mid+1, r, key);
	}
	return -1;
}

int main()
{
	int arr[] = {10,22,33,45,78,88,99,123,1234};
	int len = sizeof(arr)/sizeof(arr[0]);
	int key = 1234;

	int index = binary_search(arr, 0, len-1, key);
	
	(index == -1) ? printf("Element %d not found\n",key) : printf("Element %d is found at %d\n",key, index);
	return 0;
}

