#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define SIZE 6
struct queue

{int qdata[SIZE];
int front,rear;
}q;
void insert(int str)
{if(((q.rear==SIZE-1)&&(q.front==0))||(q.rear==q.front-1))

	{
		printf("queue is FULL\n");
		return;
	}
	q.rear=(q.rear+1)%SIZE;
	q.qdata[q.rear]=str;

	if(q.front==-1)
		q.front=0;
}
void del()
{int dstr;
	if(q.front==-1)
	{
		printf("nothing to delete\n");
		return;
	}
	dstr=q.qdata[q.front];
	if(q.front==q.rear)
	{
		q.front=q.rear=-1;
	}
	else q.front=(q.front+1)%SIZE;
}
void display()
{
	if(q.front==-1)
	{
		printf("no items\n");
	}
	int i;
	if(q.front<q.rear)
	{
		for(i=q.front;i<=q.rear;i++)
	{
		printf("%d\t",q.qdata[i]);
	}printf("\n");
	}else {
	for(i=q.front;i!=q.rear;i=(i+1)%SIZE)
	{
		printf("%d\t",q.qdata[i]);
	}printf(" %d\n",q.qdata[q.rear]);}
}
int main()
{int str;
q.front=q.rear=-1;
do {printf("1:INSERT\n2:DELETE\n3:DISPLAY\n4:EXIT\n");
int choice;

scanf("%d",&choice);
switch(choice)
{
	case 1: printf("enter the no\n");
	scanf("%d",&str);
	insert(str);break;
	case 2: del();break;
	case 3: display();break;
	case 4: exit(1);
	default : printf("invaalid");

}}while(1);

    return 0;
}

