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
    struct link_l *next,*prev;
};
typedef struct link_l node;
node *last_node=NULL;
node *get_node()
    {
    node *temp;
    temp=(node *)malloc(sizeof(node));
    return temp;
    }

node *insert_last(node *start)
{
    node *newn;
    newn=get_node();
    if(newn==NULL)
    {
        printf("error in memory allocation\n");
        return start;
    }
    printf("enetr the data \n");
    scanf("%d",&newn->data);
    newn->next=newn->prev=NULL;
    if(start->next==NULL)//assuming start->next ==null in main function;
    {
        start->next=newn;
        last_node=newn;
        start->data++;
        return start;
    }
    node *temp;
    temp=start->next;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
        temp->next=newn;
        newn->prev=temp;
        last_node=newn;
        start->data++;
        return start;
}

node *insert_pos(node *start)//inserting at given position(after that positon);
{   int pos;
    node *newn,*temp;
    newn=get_node();
    printf("enter the element to add\n");
    scanf("%d",&newn->data);
    newn->next=NULL;
    printf("enter the position(data)\n");
    scanf("%d",&pos);
    temp=start->next;
    while(temp!=NULL&&temp->data!=pos)
    temp=temp->next;
    if(temp==NULL)
    {
        printf("INVALID POSITION!!!!\n");
        free(newn);
        return start;
    }
    if(temp->next==NULL)
    {
        temp->next=newn;
        newn->prev=temp;
        last_node=newn;


    }
    else
    {
        newn->next=temp->next;
        newn->prev=newn;
        temp->next->prev=newn;
        temp->next=newn;
    }
    start->data++;
    return start;
}

node *delete_first_node(node *start)//using last node
{
    node *temp=last_node;
    if(temp==NULL)
    {
        printf("list  is empty\n");
        return start;
    }
    while(temp->prev!=NULL)
    temp=temp->prev;
    if(temp->next==NULL)
    {
        start->next=NULL;
        last_node=NULL;
    }
    else
    {
        start->next=temp->next;
        temp->next->prev=NULL;
    }
    start->data--;
    printf("delete item is %d\n",temp->data);
    free(temp);
    return start;
}

node * delete_given_pos(node *start)
{   int pos;
    node *temp;
    temp=start->next;
    if(temp==NULL)
    {
        printf("nothing to delete\n");
        return start;
    }
    printf("enter the position\n");
    scanf("%d",&pos);
    while(temp!=NULL&&temp->data!=pos)
    {temp=temp->next;}
    if(temp==NULL)
    { printf("wrong positon\n");
      return start;
    }
    else
{   if(temp->prev==NULL)
    {
        start->next=temp->next;
        if(temp->next!=NULL)
        temp->next->prev=NULL;
        start->data--;
    }
    else if(temp->next==NULL)
    {
        temp->prev->next=NULL;
        last_node=temp->prev;
        start->data--;
    }
    else
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        start->data--;
    }
    printf("deleted:%d",temp->data);
    free(temp);
}
    return start;
}
node *swap(node *start)
{
    node *temp=start->next;
    node *t1,*t2;
    int p,m,n;
    printf("enetr the two positon you want to swap\n");
    scanf("%d",&m);
    scanf("%d",&n);
    if(m>start->data || n>start->data)
    {
        printf("wrong positon\n");
        return start;
    }
    if(m>n)
    p=m;
    else
    p=n;
    for(int i=1;i<=p;i++)
    {
        if(i==m)
        t1=temp;
        if(i==n)
        t2=temp;
        temp=temp->next;
    }
    p=t1->data;
    t1->data=t2->data;
    t2->data=p;
    return start;
}
void display(node *start)
{
    node *t;
    t=start->next;
    if(t==NULL)
    {
        printf("list empty\n");
        return;
    }
    while(t!=NULL)
    {
        printf("%d\t",t->data);
        t=t->next;
    }
}

int main()
{  node *start=NULL;
   start=get_node();
   start->next=start->prev=NULL;
   start->data=0;
   int ch;
   do
   {
    printf("\n1:insert_last\n2:insert_pos\n3:delete_first_node\n4:delete_given_pos\5:swap\n6:display\n7:exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:start=insert_last(start);
        break;
        case 2: start=insert_pos(start);
        break;
        case 3: start=delete_first_node(start);
        break;
        case 4: start=delete_given_pos(start);
        break;
        case 5: start=swap(start);
        break;
        case 6:display(start);
        break;
        case 7: exit(0);
        default :printf("INVALID CHOICE!\n");

    }
   }while(1);

    return 0;
}

