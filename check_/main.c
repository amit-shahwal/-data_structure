#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{FILE *fp1;
char str;char ch;
fp1=fopen("aa.txt","r");
ch=getc(fp1);
while(ch!=EOF)
{
	ch=getc(fp1);
	if(ch=='s')
	{
		break;
}}
while(fscanf(fp1,"%c",&str)!=EOF)
{printf("%c",str);}

    return 0;
}
