#include <stdio.h>
int cdi_dtt_demod_debug=0x010;
#define CDI_DTT_DEMOD_PRINTK(dbg, lvl,n,m, fmt, args...) \
				if((dbg & lvl) )\
					do { \
						printf("%s\t%s():%d %d %d\t",__FILE__,__FUNCTION__,__LINE__,n,m); \
						printf(fmt, ## args); \
						printf("\n"); \
					} while(0)

#define deb_cdi_demod_err(n,m,args...)    printf("ERROR "); CDI_DTT_DEMOD_PRINTK(cdi_dtt_demod_debug,0x010,n,m,args)

int main()
{
    deb_cdi_demod_err(1,2,"This is error message %d",1);    
    deb_cdi_demod_err(2,3,"This is error message %d",2);    
    deb_cdi_demod_err(3,4,"Entered");    
    deb_cdi_demod_err(4,5,"Exited");    
    return 0;
}
