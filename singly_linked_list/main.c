#include<stdio.h>
#include<stdlib.h>

struct link_list
{
int info;
struct link_list *link;

};
typedef struct link_list NODE;
NODE *start=NULL;
void insert_node(int x)
{ NODE *n,*temp;
n=(NODE *)malloc(sizeof(NODE));
//t=n;
    n->info=x;
    n->link=NULL;
    if(start==NULL)
    {
        start=n;return;
    }
        temp=start;
        while (temp->link!=NULL)
        temp=temp->link;
        temp->link=n;
}

void delete()
{int ele; NODE *r;
    if(start==NULL)
    {
        printf("nothing to delete\n");
        return;
    }
r=start;
ele=r->info;
printf("the deleted elements is %d",ele);
start=start->link;
free(r);
}
void display()
{
NODE *f;
f=start;
if(f==NULL)
{printf("EMPTY\n");return;}
while (f->link!=NULL)
{
   printf("%d\t",f->info);
   f=f->link;
}
   printf("%d\t",f->info);
}
void reverse()
{
    NODE *t1,*t2;
    t1=NULL;
    t2=NULL;

    while (start!=NULL)
    {
    t2=start->link;
    start->link=t1;
    t1=start;
    start=t2;
    }start=t1;
    return;


}
void insert_pos(int x)
{  int pos;
   NODE *n,*p;
    n=(NODE *)malloc(sizeof(NODE));
    printf("enter the position\n");
    scanf("%d",&pos);
   if(pos==1)
    {   n->info=x;
        n->link=NULL;
        n->link=start;
        start=n;
        return;

    }

      n->info=x;
    n->link=NULL;
    p=start;

    for(int i=1;i<pos-1&& p!=NULL;i++)
       p=p->link;
    n->link=p->link;
    p->link=n;
    return;


}
int main()
{int ch,x;
    do
    {printf("\n1:INSERT\n2:DELETE\n3:DISPLAY\n4:REVERSE\n5:postion\n6:EXIT\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:  printf("enter the element\n");
             scanf("%d",&x);
              insert_node(x);
    break;
    case 2: delete();
    break;
    case 3: display();
    break;
    case 4: reverse();
    break;
    case 5: printf("enter the element\n");
             scanf("%d",&x);
              //insert_node(x);
        insert_pos(x);
    break;
    case 6: exit(0);
    default : printf(" INVALID OPTIONS\n");
    }

    } while (1);
    return 0;
}
