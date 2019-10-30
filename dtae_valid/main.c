#include <stdio.h>
#include <stdlib.h>


struct date
{
	int date;

	int year;
	int month;
}dt;

int main()
{
int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
scanf("%d%d%d",&dt.date,&dt.month,&dt.year);
if(dt.year%4==0){
	m[1]=29;
}
if((dt.date>m[dt.month-1])||dt.month>12)
	printf("nv\n");
else printf("true");
    return 0;
}
