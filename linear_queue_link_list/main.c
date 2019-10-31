#include <stdio.h>
#include <stdlib.h>

struct queue
{
	int data;
	 struct queue *next;
};
typedef struct queue node;
node *f=NULL,*r=NULL;

void insert()
{ node *newn;
	newn=(node *)malloc(sizeof(node));
	printf("enter the element\n");
	scanf("%d",&newn->data);
	newn->next=NULL;
	if(r==NULL)
	{
		f=newn;
		r=newn;
	}
	else
	{
		r->next=newn;
		r=newn;
	}

}

void delete()
{
	node *temp;
	int ele;
	if(f==NULL)
	{
		printf("nothing to delete\n");
		r=f=NULL;
		return;
	}
	temp=f;
	ele=temp->data;
	printf("the deleted elemt is\t%d",ele);
	f=f->next;
	free(temp);

}

void display()
{node *tt;

if(f==NULL)
	{
		printf("nothing to display\n");
		return;
	}
	tt=f;

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
