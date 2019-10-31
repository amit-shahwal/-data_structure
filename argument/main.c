#include <stdio.h>
#include <stdlib.h>

int main(int argc,char * argv[])
{
 if(argc<3){exit(0);}
int y[50],i;int sum=0;
 for(i=0;i<argc;i++)
 {
 //	x[i]=argv[i+1];
 	y[i]=atoi(argv[i+1]);
 	if(y[i]>sum){sum=y[i];}
 }printf("%d",sum);
    return 0;
}
