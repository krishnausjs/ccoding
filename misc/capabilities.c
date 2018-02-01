#include <stdio.h>

#define CAPS_MMK 8

#define to_cap_t(x) (x)
#define cap_t(x) (x)
#define CAP_TO_MASK(x) (1 << (x))
#define CAP_INIT_EFF_SET    to_cap_t(~0 & ~CAP_TO_MASK(CAPS_MMK))

int main()
{
    printf("\nValue of effective set is %x\n",CAP_INIT_EFF_SET);
    return 0;
}
