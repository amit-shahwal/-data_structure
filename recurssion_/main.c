#include <stdio.h>
#include <stdlib.h>
int fib (int n)
{
	if(n==1)
		return 1;
	else
		return n*fib(n-1);
}
int main()
{int d;
    scanf("%d",&d);
    printf("%d",fib(d));
    return 0;
}
