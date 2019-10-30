#include <stdio.h>
#include <stdlib.h>

int main(int argc,char * argv[])
{
int large=atoi(argv[1]),small=atoi(argv[1]);

 if(argc<3){exit(0);}
int y[50],i;
 for(i=0;i<argc;i++)
 {
 //	x[i]=argv[i+1];
 	y[i]=atoi(argv[i+1]);
 	//large=y[0];small=y[0];

 	if(y[i]>large){large=y[i];}
 	if(y[i]<small){small=y[i];}
 }printf("The largest is %d \n The smallest id %d",large,small);
    return 0;
}
