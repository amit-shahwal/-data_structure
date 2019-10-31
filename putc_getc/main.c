#include <stdio.h>
#include <stdlib.h>



int main()
{
	char ch,ch1;
	printf("enter the charctyer\n");
	scanf("%c",&ch);
	FILE *fp;
	fp=fopen("nxtf.txt","w");
	putc(ch,fp);
	fclose(fp);
	fp=fopen("nxtf.txt","r");
	getc(fp);
	printf("%c",ch);
	fclose(fp);
	return 0;
}
