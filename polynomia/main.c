#include <stdio.h>
#include <stdlib.h>

struct polynomial
{
	int coff,ex1,ex2;
	struct polynomial *next;

};

typedef struct polynomial node;

node *insert_poly(node *h1)
{  char ch;node *p1=NULL;
	printf("enter the polynomial\n");
	do{
		node *newn;
		newn=(node *)malloc(sizeof(node));
		printf("enter the cofficent and power of x and power of y\n");
		scanf("%d%d%d",&newn->coff,&newn->ex1,&newn->ex2);
		newn->next=NULL;
		if(h1==NULL)

		{	h1=newn;
			p1=h1;
		}
		else
		{
		p1->next=newn;
		p1=p1->next;
		}
	printf("if you want enter again press y\n");
	scanf(" %c",&ch);
	}
	while(ch=='Y' || ch=='y');
return h1;

}
void display(node *h1)
{
	node *p1=NULL;
	p1=h1;
	while(p1!=NULL)
		{
		printf("%dx^%dy^%d",p1->coff,p1->ex1,p1->ex2);
		p1=p1->next;
		if(p1!=NULL)
		printf("+");
		}
}

void addition(node *h1,node *h2)
{
	node *p1=NULL,*p2=NULL;
	p1=h1;
	p2=h2;
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1->ex1==p2->ex1)
		{
			if(p1->ex2==p2->ex2)
			printf("%dx^%dy^%d",p1->coff+p2->coff,p1->ex1,p2->ex2);
			p1=p1->next;
			p2=p2->next;
		}
		else if(p1->ex1>p2->ex2)
		{
			printf("%dx^%dy^%d",p1->coff,p1->ex1,p1->ex2);
			p1=p1->next;
		}
		else
		{
			printf("%dx^%dy^%d",p2->coff,p2->ex1,p2->ex2);
			p2=p2->next;
		}
		if(p1!=NULL||p2!=NULL)
			printf("+");

	}
	while(p1!=NULL)
	{
		printf("%dx^%dy^%d",p1->coff,p1->ex1,p1->ex2);
		p1=p1->next;
	}
	while(p2!=NULL)
	{
		printf("%dx^%dy^%d",p2->coff,p2->ex1,p2->ex2);
		p2=p2->next;

	}
}
int main()
{ 	node *h1=NULL,*h2=NULL;
	int ch;
    do{
    printf("\n1:inert polynomial_1\n2:inert polynomial_2\n");
    printf("3:display_p1\n4:display_p2\n5:addition_p1+p2_\n");
    printf("6:exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
    	case 1: h1=insert_poly(h1);
    	break;
    	case 2: h2=insert_poly(h2);
    	break;
    	case 3: display(h1);
    	break;
    	case 4: display(h2);
    	break;
    	case 5: addition(h1,h2);
    	break;
    	case 6: exit(0);
    	default: printf("INVALID CHOICE\n");

    }
    }while(1);
    return 0;
}
