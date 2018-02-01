#include <stdio.h>

#define MMK_TEL 0x0
int glv;

#define IS_SRC_BIT_SET(num,bit) (((num)&(1<<(bit)))?1:0)
#define SET_SRC_BIT_SET(num,bit) (num |= (1<<(bit)))
int main()
{
   int ret;
   glv=0;
#if 0
   printf("\n%x\n",(1<<4));
   if(MMK_TEL&2)
   {
	printf("\n bit set \n");
   }
   else
   {
	printf("\n bit not set \n");
   }
#else
   printf("\n%x\n",(0|(1<<0)));
   ret=SET_SRC_BIT_SET(glv,2);
	printf("\n value of glv is %d \n",glv);
   ret=IS_SRC_BIT_SET(glv,2);
   if(ret)
   {
	printf("\n bit 2 is set ret=%d glv=%d\n",ret,glv);
   }
   else
   {
	printf("\n bit 2 is not set ret=%d glv=%d\n",ret,glv);
   }
#endif
   return 0;
}
