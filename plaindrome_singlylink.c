#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct plaindrome_singlylink
{
    int data;
    struct plaindrome_singlylink *next;

};
typedef struct plaindrome_singlylink node;
node *start;
void insert()
{

    node *newn=(node *)malloc(sizeof(node));
    newn->next=NULL;
    printf("enter the data\n");
    scanf("%d",&newn->data);
    if(start==NULL)
    {
        start=newn;
        return;
    }
    node *t=start;
    while (t->next!=NULL)
    {
        t=t->next;
    }
    t->next=newn;
}

void display()
{
    node *t=start;
    while (t!=NULL)

    {
 printf("%d",t->data);t=t->next;
    }

}
void check_palin()
{node *t=start;
    int stack[200];
    int top=-1;
    while (t!=NULL)
    {
        stack[++top]=t->data;
        t=t->next;
    }
    for(int i=0;i<top;i++)
    {
        if(stack[i]==stack[top-i])
        continue;
        else
        {
            printf("not palin\n");
            return;
        }
    }
    printf("palindrome\n");
    return;

}
int main()
{
    int ch;
    do
    {scanf("%d",&ch);
switch (ch)
{
case 1:insert();break;
case 2: display();
break;
case 3: check_palin();
break;


}}
while (1);


}
