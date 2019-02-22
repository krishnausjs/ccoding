// Function to return the only odd occurring element
// function to convert decimal to binary
void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[1000];
 
    // counter for binary array
    int i = 0;
    while (n > 0) {
 
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
 
    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%d",binaryNum[j]);
        
}

int findOdd(int arr[], int n) {
   int res = 0, i;
   for (i = 0; i < n; i++)
   {
     res ^= arr[i];
     decToBinary(res);
     printf("\n");
     decToBinary(arr[i]);
     printf("\n");
     printf("i=%d , arr[%d]=%d 0x%x(%d)\n\n",i,i,arr[i],res,res); 
   }
   printf("\n");

   return res;
}
 
int main(void) {
   int arr[] = {12, 12, 14, 90, 14, 12, 12};
   int n = sizeof(arr)/sizeof(arr[0]);
   printf ("The odd occurring element is %d ", findOdd(arr, n));
   return 0;
}