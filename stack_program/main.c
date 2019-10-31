#include <stdio.h>
#include <stdlib.h>
struct STACK
{
	int data[10];
	int top;
}st;
void push(struct STACK *st,int ele)
{
	if(st->top==9){printf("overflow\n");}
	st->top++;
	st->data[st->top]=ele;

}
 void pop(struct STACK *st)
{int ele=-1;
	if(st->top==-1){printf("underflow\n");return (ele);}
	else{
	ele=st->data[st->top];
	st->top--;
	printf("%d",ele);
	return;

}}
void display(struct STACK *st)
{int i;
	if (st->top==-1){printf("stack is empty\n");return;}
	printf("stacks:\n");
	for( i=0;i<=st->top;i++)
	{printf("%d\n",st->data[i]);}
}
void inti(struct STACK *st)
{
	st->top=-1;
}
void palin(struct STACK *st)
{int i;
	for(i=0;i<=st->top;i++)
	{
		if(st->data[i]==st->data[st->top-i])
			{continue;}
		else {printf("this is not palindrome\n");return;}
	}printf("stack is palindrome\n");
}
int main()
{inti(&st);
int ele,ch;
printf("1:push\n2:pop\n3:display\n4:palindrome\n5:exit\n");
do{ printf("\nenter your choice:");
scanf("%d",&ch);
switch(ch)
{
	case 1: printf("enetr the element\n");
	scanf("%d",&ele);push(&st,ele);break;
	case 2: pop(&st);break;
	case 3: display(&st);break;
	case 4: palin(&st);break;
	case 5 : exit(0);
	default : exit(0);
}
}while(1);
 return 0;
}
