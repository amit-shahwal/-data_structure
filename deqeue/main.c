#include <stdio.h>
#include <stdlib.h>
struct deqeue
{
	int data;
	struct deqeue *next;
	struct deqeue *prev;
};
typedef struct deqeue node;
node *f=NULL,*r=NULL;
node *start=NULL;
typedef struct deqeue node;
void insert_front()
{	node *newn;
	newn=(node *)malloc(sizeof(node));
	printf("enter the element\n");
	scanf("%d",&newn->data);
	newn->next=NULL;
	newn->prev=NULL;
	if(r==NULL)
	{
			f=r=newn;
			return;
	}
	newn->next=f;
	f->prev=newn;
	f=newn;
}
void insert_rear()
{	node *newn;
	newn=(node *)malloc(sizeof(node));
	printf("enter the element\n");
	scanf("%d",&newn->data);
	newn->next=NULL;
	newn->prev=NULL;
	if(r==NULL)
	{
			f=r=newn;
			return;
	}
	r->next=newn;
	newn->prev=r;
	r=newn;

}

void delete_front()
{
	if(f==NULL)
	{
		printf("nothing to delete\n");
		r=f=NULL;
		return;
	}
	node *t;
	t=f;
	if(t->next==NULL)
	 {	printf("deleted :%d\n",t->data);
	 	f=NULL;
		free(t);
		return;
	 }
f=t->next;
printf("deleted :%d\n",t->data);
 free(t);
}
void delete_end()
{
	if(r==NULL)
	{
		printf("nothing to delete\n");
		r=f=NULL;
		return;
	}
	node *t;
	t=r;
	if(t->prev!=NULL)
	{
	printf("%d\n",t->data);
	t->prev->next=NULL;
	r=t->prev;
	free(t);
	return;
	}
	if(t->prev==NULL)
	{printf("%d\n",t->data);
		r=NULL;
		free(t);
		return;
	}
}
void display_front()
{
	if(f==NULL)
	{
		printf("nothing to display\n");
		return;
	}
	node *temp;
	temp=f;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}

}
void display_rear()
{
	if(r==NULL)
	{
		printf("nothing to display\n");
		return;
	}
	node *temp;
	temp=r;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->prev;
	}

}
int main()
{int ch;
do{
    printf("\n1:insert_front\n2:insert_end\n3:delete_front\n4:delete_end\n5:display_front\n6:display_rear\n7:exit\n");
    scanf("%d",&ch);
	switch(ch)
	{
		case 1: insert_front();
		break;
		case 2:insert_rear();
		break;
		case 3: delete_front();
		break;
		case 4: delete_end();
		break;
		case 5:display_front();
		break;
		case 6: display_rear();
		break;
		case 7: exit(0);
		}

	}while(1);
    return 0;
}
