#include <stdio.h>
#include <stdlib.h>

struct d_link
{
	int data;
	struct d_link *prev,*next;
};
typedef struct d_link node;
node *next=NULL; node *prev=NULL;node *start=NULL;
void insert()
{	node *newn,*t;
	newn=(node *)malloc(sizeof(node));
	printf("enter the data\n");
	scanf("%d",&newn->data);
	newn->next=newn->prev=NULL;
	if(start==NULL)
	{
		start=newn;
		return;
	}
	t=start;
	while(t->next!=NULL)
	t=t->next;
	t->next=newn;
	newn->prev=t;
}
void delete()
{	node *temp;
//	int ele;
	if(start==NULL)
	{
		printf("nothing to delete\n");
		next=prev=NULL;
		return;
	}
	temp=start;
	printf("deleted elemnt \t%d",temp->data);
	start=start->next;
	free(temp);
}
void display()
{	node *tt;
	if(start==NULL)
	{
		printf("nothing to display\n");
		return;
	}

	tt=start;

	while(tt!=NULL)
	{
		printf("%d\t",tt->data);
		tt=tt->next;
	}
}
int main()
{int ch;
do {
    printf("\n1:insert\n2:delete\n3:display\n");
    scanf("%d",&ch);
    switch(ch)
    {
    	case 1:insert();
    	break;
    	case 2: delete();
    	break;
    	case 3: display();
    	break;
    	case 4: exit(0);
    	default : printf("INVALID CHOICE");
    }
}while(1);
    return 0;
}

