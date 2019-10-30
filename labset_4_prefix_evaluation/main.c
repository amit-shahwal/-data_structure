#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>

struct STACK
{
	int top;
	int sdata[50];
}st;
void push(struct STACK *st,int val)
{  st->top++;
 st->sdata[st->top]=val;

}
int pop(struct STACK *st)
{
	int val;
	val=st->sdata[st->top];
	st->top--;
	return val;
}
void intial(struct STACK *st)
{
	st->top=-1;
}
int main()
{intial(&st);
	char expr[50],symbol;
int res,op1,op2;
int sy[26];int i;
printf("enter the expression\n");
gets(expr);
fflush(stdin);
for( i=0;i<26;i++)
{
	sy[i]=-1;
}

for(i=strlen(expr)-1;i>=0;i--)
{
	symbol=expr[i];
	if(isdigit(symbol))
	{
		push(&st,(symbol-'0'));
	}
	else if(isalpha(symbol))
	{
		if(symbol>='a'||symbol<='z')
			symbol=symbol-32;
		if(sy[symbol-'A']==-1){
		printf("enter the value of %c \n",symbol);
		scanf("%d",&sy[symbol-'A']);}

	push(&st,sy[symbol-'A']);}
	else
	{
		op1=pop(&st);
		op2=pop(&st);
		switch(symbol)
		{
			case '+': res=op1+op2;break;
			case '-': res=op1-op2;break;
			case '/' : res =op1/op2;break;
			case '*' :res=op1*op2;break;
		}push(&st,res);

	}
}res=pop(&st);
printf("The following %s prefix expression evaluation is %d",expr,res);


    return 0;
}
