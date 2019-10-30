#include <stdio.h>
#include <stdlib.h>
struct emplyoee
{char name[50];
int id;
char dep[50];
int sal;
int age;

}ep[10];
int main()
{int n,i,id,ph;char name[50],dep[50];int k,age,sal;

printf("enter the no of data you want to enter\n ");
scanf("%d",&n);

for(i=0;i<n;i++)
{printf("enter the details of %d:user\n 1:name:\n 2:id:\n 3:dep\n 4:age\n 5: sal",i+1);
	scanf("%s %d %s %d %d",ep[i].name,&ep[i].id,&ep[i].dep,&ep[i].age,&ep[i].sal);

}
FILE *fp;

fp=fopen("nw.txt","w");
for(i=0;i<n;i++)
{

fprintf(fp,"%s %d %s %d %d",ep[i].name,ep[i].id,ep[i].dep,ep[i].age,&ep[i].sal);
}
    fclose(fp);
    //printf("enter the file name");
//scanf("%s",cd);2
fp=fopen("nw.txt","r");
while((fscanf(fp,"%s %d %s %d %d",name,&id,dep,&age,&sal))!=EOF)
{
	printf("to display on monitor\n");
	printf("%s %d %s %d %d ",name,id,dep,age,sal);

}
fclose(fp);
fp=fopen("nw.txt","r");
printf("enter the id you want to search\n\n");
scanf("%d",&k);
for(i=0;i<n;i++)
{
	if(ep[i].id==k)
	{printf("%s %d %s %d %d",ep[i].name,ep[i].id,ep[i].dep,ep[i].age,ep[i].sal);break;
	}
}

    return 0;
}
