//a) program to calculate sum of each digit in a number and to reverse it

#include<stdio.h>

int main()
{
   long num, rev = 0;
   int rem, sum = 0;
   printf("enter any number :");
   scanf("%ld", &num);
   while(num != 0)
   {
     rem = num%10;
     rev = rev*10+rem;
     sum = sum + rem;
     num = num/10;
   }
   printf("\nsum of digits = %d\nreverse of number = %ld", sum, rev);
   return 0;//
}
