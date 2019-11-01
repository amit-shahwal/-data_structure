/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct link_l
{
    int data;
    struct link_l *next;
};
   typedef struct link_l node;

node *insert_beging_last_node(node *h1)
{
    node * newn,*p;
    newn=(node *)malloc(sizeof(node));
    printf("enetr the data\n");
    scanf("%d",&newn->data);
    newn->next=NULL;
    if(h1==NULL)
    return newn;
    p=NULL;
    node *t=h1;
    while(t->next!=NULL)
    {
        p=t;
        t=t->next;
    }
    if(p!=NULL)
    {p->next=newn;}
     newn->next=t;
     if(p==NULL)
     {
         return newn;
     }
    return h1;
}

void display(node *h1)
{
    node *t;
    t=h1;
    if(t==NULL)
    {
        printf("empty\n\n");
        return;
    }
    while(t!=NULL)
    {
        printf("%d\t",t->data);
        t=t->next;
    }
}

int main()
{   int ch;
    node *h1=NULL;
    do
    {
    printf("\n1:insert_beging_last_node\n2:display\n3:exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: h1=insert_beging_last_node(h1);
        break;
        case 2: display(h1);
        break;
        case 3: exit(0);

    }
    }while(1);
    return 0;
}
