#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct evaluation_polynomial_singly_linkList
{
    int coff;
    int ex;
    struct evaluation_polynomial_singly_linkList *next;

};
typedef struct evaluation_polynomial_singly_linkList node;

node *insert(node *list)
{ int ch;
      do
{
    node *newn;
    newn=(node *)malloc(sizeof(node));
    printf("enter the coff");
    scanf("%d",&newn->coff);
    printf("enter the exponential\n");
    scanf("%d",&newn->ex);
    newn->next=NULL;
    node *p1;
    if(list==NULL)
    {
        list=newn;
        p1=newn;

    }
    p1->next=newn;
    p1=p1->next;
printf("to write more press 1 ");
scanf("%d",&ch);
}while (ch==1);
return list;
}

void eval(node *list,int x)
{   node *t;

    int sum=0;

    t=list;
    while (t!=NULL)
    {
        sum=sum+(t->coff)*(pow(x,t->ex));
        t=t->next;
    }
    printf("the sum of polynomialis %d",sum);


}
int main()
{node *list=NULL;
    int ch,x;
    do
    {
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:list=insert(list);break;
        case 2:printf("enter the val of x\n");
        scanf("%d",&x);
        eval(list,x);
            break;


        }
    } while (1);

}
