//Problem : Sum of bit differences among all pairs

//Description : Given an integer of n integers, find sum of bit differences in all pairs that can be formed from array elements. Bit differences of a pair (x,y) is count of different bits at same positions in binary representation of x and y.

// Example:  Bit difference between 2 and 7 is 2. Binaray representation of 2 is 010 and 7 is 111. First and last digits differe in two numbers.
//
// Example : Bit differnce between all pairs of 1 and 2 is
// Pair (1,1) = (0001, 0001) = bit difference = 0
// Pair (1,2) = (0001, 0010) = bit difference = 2
// Pair (2,1) = (0010, 0001) = bit difference = 2
// Pair (2,2) = (0010, 0010) = bit difference = 0
// Sum of above is 4
//
// Now another example  input arr = {1,3,5}
// Pair (1,1) = (0001,0001) = 0
// Pair (1,3) = (0001,0011) = 1
// Pair (1,5) = (0001,0101) = 1
// Pair (3,1) = (0011,0001) = 1
// Pair (3,5) = (0011,0101) = 2
// Pair (3,3) = (0011,0011) = 0
// Pair (5,5) = (0101,0101) = 0
// Pair (5,1) = (0101,0001) = 1
// pair (5,3) = (0101,0011) = 2
// Total  = 8

//Analysis: Lets consider XOR operation.
// 1 1 = 0
// 1 0 = 1
// 0 1 = 1
// 0 0 = 0
// So, if there is any difference in bits we can use XOR
// Now, for one pair, say (3,5)
// 3 = 0011
// 5 = 0101
// XOR(3,5) = 0110
// Number of Bits set in (XOR(3,5)) = 2.
// So, we can write a function that gets XOR of a pair and counts number of bits in it.

#include <stdio.h>

unsigned int xor_of_pair(unsigned int x, unsigned int y)
{
	return x^y;
}

int bit_differences(unsigned int x, unsigned int y)
{
	unsigned int cal_xor;
	cal_xor = xor_of_pair(x,y);
	int num_bits;

	while(cal_xor)
	{
	    cal_xor = cal_xor & (cal_xor-1);
	    ++num_bits;
	}
	return num_bits;
}


int main()
{
	int arr[]={1,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
	int i,j;
    int bit_diff_sum=0;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
			    printf("Calculating the differences between %d and %d\n",arr[i],arr[j]);
			    bit_diff_sum = bit_differences(arr[i],arr[j]);
			}
		}
	}
	printf("Bit difference between pair 1,3,5 is %d\n",bit_diff_sum);
	return 0;
}

//Time Complexity : Time Complexity of this program is O(n^2). This is the worst case scenario.
//We need to optimize this further.
