#include <stdio.h>
#include <stdlib.h>
struct emplyoee
{char name[50];
int id;
int ph;

}ep[10];
int main()
{int n,i,id,ph;char name[50];

printf("enter the no of data you want to enter\n ");
scanf("%d",&n);

for(i=0;i<n;i++)
{printf("enter the details of user\n name:\n id:\n ph\n of %d",i+1);
	scanf("%s %d %d",ep[i].name,&ep[i].id,&ep[i].ph);

}char c[5];
FILE *fp;
scanf("%s",c);
fp=fopen(c,"w");
for(i=0;i<n;i++)
{

fprintf(fp,"%s %d %d",ep[i].name,ep[i].id,ep[i].ph);
}
    fclose(fp);char cd[40];
    //printf("enter the file name");
//scanf("%s",cd);2
fp=fopen(c,"r");
while((fscanf(fp," %s %d %d",name,&id,&ph))!=6)
{
	printf("to display on monitor\n");
	printf("%s %d %d",name,id,ph);

}
fclose(fp);

    return 0;
}
