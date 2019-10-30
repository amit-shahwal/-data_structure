#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define SIZE 5
struct queue

{char qdata[SIZE][30];
int front,rear;
}q;
void insert(char str[])
{
	if(q.rear==SIZE-1)
	{
		printf("queue is FULL\n");
	}
	q.rear++;
	strcpy(q.qdata[q.rear],str);
	if(q.front==-1)
		q.front=0;
}
void del()
{char dstr[30];
	if(q.front==-1)
	{
		printf("nothing to delete\n");
	}
	strcpy(dstr,q.qdata[q.rear]);
	if(q.front==q.rear)
	{
		q.front=q.rear=-1;
	}
	else q.front++;
}
void display()
{
	if(q.rear==-1)
	{
		printf("no items\n");
	}
	int i;
	for(i=q.front;i<=q.rear;i++)
	{
		printf("%s\t",q.qdata[i]);
	}printf("\n");
}
int main()
{char str[30];
q.front=q.rear=-1;
do {printf("1:INSERT\n2:DELETE\n3:DISPLAY\n4:EXIT\n");
int choice;

scanf("%d",&choice);
switch(choice)
{
	case 1: printf("enter the string\n");
	scanf("%s",str);
	insert(str);break;
	case 2: del();break;
	case 3: display();break;
	case 4: exit(1);
	default : printf("invaalid");

}}while(1);

    return 0;
}
