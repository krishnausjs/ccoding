#include <stdio.h>

int main()
{
    int i=0; 
    float tol_value=0.0;

    for(i=0;i<=15;i++)
    {
        printf("\n Minimum pulse tolerance value for [%d] is %f",i,((901.63+(i*136.71)+13.02)));
        printf("\n Maximum pulse tolerance value for [%d] is %f\n",i,((1038.33+(i*136.71)-13.02)));
    }

    return 0;
}
