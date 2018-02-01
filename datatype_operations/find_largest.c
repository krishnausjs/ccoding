#include <stdio.h>

int main ()
{
  int arr[] = {1, 20, 9, 12, 19, 17, 10, 5};
  printf ( "%d\n", arr[FindMaxArr ( arr, 0, 8 )] );
  return 0;
}

int FindMaxArr( int arr[], int lMost, int rMost )
{
  if ( lMost == rMost - 1 )     return lMost;  
  rMost = FindMaxArr(arr, lMost+ 1, rMost);
  printf("\nDbg1 lMost is %d, rMost is %d \n",lMost,rMost);
  return arr[rMost] > arr[lMost] ? rMost : lMost;
}
