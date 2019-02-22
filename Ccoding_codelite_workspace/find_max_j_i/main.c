#include <stdio.h>
#include <stdlib.h> 

/* For a given array arr[], returns the maximum j – i such that 
	arr[j] > arr[i] */
int maxIndexDiff(int arr[], int n) 
{ 
	int maxDiff = -1; 
	int i, j; 

	for (i = 0; i < n; ++i) 
	{ 
		for (j = n-1; j > i; --j) 
		{ 
			if(arr[j] > arr[i] && maxDiff < (j - i)) 
				maxDiff = j - i; 
		} 
	} 
    printf("Value of i is %d and j is %d\n",i,j);
	return maxDiff; 
} 

int main() 
{ 
	int arr[] = {9, 2, 3, 4, 5, 6, 7, 8, 18, 0}; 
    //int arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
	int n = sizeof(arr)/sizeof(arr[0]); 
	int maxDiff = maxIndexDiff(arr, n); 
	printf("Max Diff is %d\n",maxDiff);
	return 0; 
} 

// This code is contributed 
// by Akanksha Rai(Abby_akku) 
