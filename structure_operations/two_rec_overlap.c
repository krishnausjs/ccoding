#include <stdio.h>

typedef struct point {
    int x, y;
}Point;

int overlapRec(Point L1, Point R1, Point L2, Point R2)
{
    if(L1.x > R2.x || L2.x > R1.x)
        return 0;

    if(L1.y < R2.y || L2.y < R1.y)
        return 0;
    return 1;
}

int main()
{
    int overlap=0;
    Point P1={0,10};
    Point R1={10,0};
    Point P2={5,5};
    Point R2={15,0};

    overlap = overlapRec(P1,R1,P2,R2);
    if(overlap)
        printf("Rectangles overlap\n");
    else
        printf("Rectangles doesnt overlap\n");
    return 0;
}
