#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node *next;
};
typedef struct node NODE;
NODE *START=NULL;

void insert_end(int x)
{
	NODE *t,*temp;
	t=(NODE *)malloc(sizeof(NODE));
	if(START==NULL)
	{
		START=t;
		START->data=x;
		START->next=NULL;
		return;
	}
	temp=START;
	while(temp->next!=NULL)
		temp=temp->next;

	temp->next=t;
	t->data=x;
	t->next=NULL;
	return;
}

void delete()
{
	int p;
	if(START==NULL)
	{
		printf("nothing to delete\n");
		return;
	}
	NODE *t;
	t=START;
	p=START->data;
	printf("\ndeleted:%d\n",p);
	START=t->next;
	free(t);
}

void display()
{NODE*t;
	t=START;
	if(t==NULL)
	{
		printf("list is empty\n");
		return;
	}
	printf("elements are:->\n");
	while(t->next!=NULL)
	{
		printf("\n%d\n",t->data);
		t=t->next;
	}
	printf("\n%d\n",t->data);
}

void inverse()
{NODE *t;
t=START;

while(t->next!=NULL)
	t=t->next;
while(START->next!=t->next)
{   START=START->next;
	printf("%d\n",t->data);
	}
printf("%d",t->data);

}


int main()
{
	int ch;
	int ele;
	do
	{
		printf("\n1:insert\n2:display\n3:delete\n4:exit\n");
		printf("\nenter your chioce\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter the element\n");
					scanf("%d",&ele);
					insert_end(ele);
					break;
			case 2: display();
					printf("\n");break;
	        case 3: delete();break;

	        case 5: inverse();break;
			case 4: exit(0);
		}
   }while(1);
   return 0;
}
