#include<stdio.h>
#include<math.h>

int main() {

printf ("sizeof unsigned int = %d bytes.\n", sizeof(unsigned int));
printf ("sizeof unsigned long long = %d bytes.\n", sizeof(unsigned long long));

printf ("max unsigned int = %d\n", (int)(pow(2, 32) - 1));
printf ("max unsigned long long = %llu (0x%x)\n", (unsigned long long)(pow(2, 64) - 1),(unsigned long long)(pow(2, 64) - 1));

}
