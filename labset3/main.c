#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>

struct STACK
{int arr[50];
int top;
}st;
int precd(char symbol)
{
	switch(symbol)
	{
		case '#' :return -1;
		case '(' : return 0;

		case '+':
			case '-' : return 1;
			case '*' :
				case '/' :return 2;
				case '^' :return 3;
				}
}
void push(struct STACK *st,char symbol)
{st->top++;
	st->arr[st->top]=symbol;
}
char pop(struct STACK *st)
{char ch;
	ch=st->arr[st->top];
	st->top--;
	return ch;
}
void inti(struct STACK *st)
{
	st->top=-1;
}

int main()
{inti(&st);
char infix[50],postfix[50];
char symbol;int i,j=0;
push(&st,'#');
printf("\nENTER THE INFIX EXPRESSION\n");
gets(infix);
fflush(stdin);
for(i=0;i<strlen(infix);i++)
{
	symbol=infix[i];
	if(isalnum(symbol))
	{
		postfix[j++]=symbol;
	}
	else if (symbol=='(')
	{
		push(&st,symbol);
	}
	else if (symbol==')')
	{
		while(st.arr[st.top]!='(')
		{
			postfix[j++]=pop(&st);
		}
pop(&st);
	}
	else{
	while(precd(st.arr[st.top])>=precd(symbol))
{
	postfix[j++]=pop(&st);
}	push(&st,symbol);
}}
while(st.arr[st.top]!='#')
{postfix[j++]=pop(&st);
}postfix[j]='\0';
printf("\nTHE CORRESPONDING POSTFIX EXPRESSION: %s",postfix);

return 0;
}
