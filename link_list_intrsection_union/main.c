#include <stdio.h>
#include <stdlib.h>
struct list
{
	int sdata;
	struct list *link;
};
typedef struct list NODE;
NODE * insert(NODE *list,int ele)
{
	NODE *newn,*temp,*pre;
    newn=(NODE*)malloc(sizeof(NODE));
	if(newn==NULL)
	{
		printf("errror in memory allocating\n");
		return list;
	}
    newn->sdata=ele;
	newn->link=NULL;
	if(list==NULL)
		return newn;
	temp=pre=list;
while(temp!=NULL&&temp->sdata<=ele)
  {
	pre=temp;
	temp=temp->link;
  }
  if(pre->sdata>=ele)
    {
	newn->link=pre;
	list=newn;
    }
  else	{
		pre->link=newn;
		newn->link=temp;
		}
	return list;
}
void display(NODE * list)
{
	if(list==NULL)
	{
		printf("empty\n");
		return;
	}
	printf("list\n");
	while(list!=NULL)
	{
		printf("%d\t",list->sdata);
		list=list->link;

	}
}
int search(NODE* slist,int ele)
{ if(slist==NULL)
		return 0;
	while(slist!=NULL&&slist->sdata<=ele)
	{
		if(slist->sdata==ele)
			return 1;
		slist=slist->link;
	}
}
 NODE * unions(NODE* list1,NODE* list2)
{
	NODE *ulist=NULL;
	if(list1==NULL&&list2==NULL)
		return ulist;
		while(list1!=NULL)
	{
		if(!search(ulist,list1->sdata))
			ulist=insert(ulist,list1->sdata);
		list1=list1->link;
	}
	while(list2!=NULL)
	{
		if(!search(ulist,list2->sdata))
			ulist=insert(ulist,list2->sdata);
		list2=list2->link;
	}
	return ulist;
}
NODE *intersect(NODE* list1,NODE* list2)
{
	NODE *ilist=NULL;
	if(list1==NULL&&list2==NULL)
		return ilist;
	while(list1!=NULL)
	{
		if(search(list2,list1->sdata))
			if(!search(ilist,list1->sdata))
			ilist=insert(ilist,list1->sdata);
		list1=list1->link;
	}
	return ilist;
}
int main()
{NODE *list1=NULL,*list2=NULL,*ilist=NULL,*ulist=NULL;
int choice,ele,ch;

do
	{
	printf("\n1.insert_list1\n2.insert_list2\n3union\n4.intersection\n5.display\n");
    scanf("%d",&choice);
    switch(choice)
    {
    	case 1:printf("enter the element\n");
    	scanf("%d",&ele);
    	list1=insert(list1,ele);
    	break;
    	case 2:printf("enter the element\n");
    	scanf("%d",&ele);
    	list2=insert(list2,ele);
    	break;
    	case 3:ulist=unions(list1,list2);
    	break;
    	case 4:ilist=intersect(list1,list2);
    	break;
    	case 5:printf("\n1.list1\n2.list\n3.union\n4.intersection\n");
    	scanf("%d",&ch);
    	switch(ch)
    	{
    		case 1:printf("list is\n");
    		       display(list1);break;
			case 2:printf("list is\n");
    		       display(list2);break;
    		case 3:printf("list is\n");
					display(ulist);break;
    		case 4:printf("list is\n");
					display(ilist);break;
    		default:printf("INVALID\n");

    	}break;
    	case 6:exit(0);


    }
	}while(1);
return 0;
}
