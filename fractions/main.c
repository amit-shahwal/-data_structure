#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int num;
    int den;
}fraction;
int main()
{
    fraction f1,f2,f3;
    printf("enter the first fraction\n");
    scanf("%d %d",&f1.num,&f1.den);
    printf("enter the second fraction\n");
    scanf("%d %d",&f2.num,&f2.den);
    f3.num=(f1.num*f2.den)+(f2.num*f1.den);
    f3.den=f1.den*f2.den;
    printf("sum is %d/%d",f3.num,f3.den);


    return 0;
}
