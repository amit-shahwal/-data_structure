/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct link
{
    int data;
    struct link * next;

};
typedef struct link node ;
node *start=NULL;
void insert()
{
 node *newn;
 newn=(node *)malloc(sizeof(node));
 printf("enter the ele\n");
 scanf("%d",&newn->data);
 newn->next=NULL;
 if(start==NULL)
 {
     start=newn;
     return;
 }
 node *t=start;
 while(t->next!=NULL)
    {t=t->next;}
    t->next=newn;
}
void display()
{
    node *t1=start;
    while(t1!=NULL)
    {
        printf("%d\t",t1->data);
        t1=t1->next;
    }
}
void sort()
{   int ele;
    node *t1;
    node *t2;
    t1=start;
    while(t1->next!=NULL)
    {
        t2=t1->next;
        while(t2!=NULL)
        {
            if(t1->data > t2->data)
            {
                ele=t1->data;
                t1->data=t2->data;
                t2->data=ele;
            }
            t2=t2->next;
        }t1=t1->next;
    }

return;}
int main()
{ int ch;
    do{
    printf("\n1:insert 2:display\n3: sort");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: insert();
        break;
        case 2: display();
        break;
        case 3: sort();
        break;

    }
}while(1);

    return 0;
}
