#include <stdio.h>
#include <stdlib.h>
struct stac
{
	int data;
	struct stac *next;
};
typedef struct stac stack;
stack *push(stack *st)
{
	stack *newn=NULL;
	int ele;stack *temp;
	temp=st;
	newn=(stack *)malloc(sizeof(stack));
	if(newn==NULL)
	{
		printf("error in MA\n");
		return st;
	}
	printf("enetr the elements\n");
	scanf("%d",&ele);
	newn->data=ele;
	newn->next=NULL;
	if(st==NULL)
	{st=newn;
		return st;
	}

	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newn;
	newn->next=NULL;
	return st;
}
stack *pop(stack *st)
{
	stack *temp,*pre;
	if(st==NULL)
	{
		return st;
	}
	temp=st;
	pre=NULL;
	while(temp->next!=NULL)
	{pre=temp;
		temp=temp->next;

	}

	printf("deleted %d \n",temp->data);
	free(temp);
	if(pre!=NULL)
	{
	pre->next=NULL;
	}
	else st=pre;
	return st;
}
void display(stack *st)
{
	while(st!=NULL)
	{	printf("\t %d\t",st->data);
		st=st->next;
	}
}

int main()
{int ch;
stack* st=NULL;
do{
    printf("\n1.push\n2.pop\n3.display\n");
   scanf("%d",&ch);
   switch(ch)
   {
   	case 1:st=push(st);break;
   	case 2:st=pop(st);break;
   	case 3:display(st);break;
   	case 4:exit(0);
   	default:printf("INVALID\n");
   }}while(1);
    return 0;
}
