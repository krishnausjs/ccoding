#include <stdio.h>
#include <malloc.h>

#define PSIZE(a) ((*((long int*)(a)-1))&~3 - sizeof(long int*))

#define __malloc malloc
#undef malloc
#define malloc(_size ) \
  ({ printf( "%s: Calling malloc(%d) from line %d, filename: %s\n", __func__, _size, __LINE__, __FILE__ ); \   __malloc( _size ); })

int main()
{
   int *ptr;
   int i;
   int bytes_to_alloc;
   //printf("Enter the bytes to allocate \n");
   //scanf("%d",&bytes_to_alloc);
   ptr=(int*)malloc(64);

   if(ptr==NULL) 
   {
       printf("Failed to allocate memory \n"); 
       return 0;	
   }
   printf("Memory pointer is 0x%x and requested for %d bytes\n",ptr,bytes_to_alloc);
   printf("byte 1  %d\n",*(ptr-1));
   printf("byte 2  %d\n",*(ptr-2));
   printf("byte 3  %d\n",*(ptr-3));
   printf("byte 4  %d\n",*(ptr-4));
   printf("Freed data will be  %ld\n",*(ptr-2));
   printf("usuable size is  %ld\n",PSIZE(ptr));
   free(ptr);
}
