// Solving Postfix problem using created algo 
#include<stdio.h>
struct stack {
	char array[10];
	int top;
};
void init (stack *);   // initializing the value of top as -1
void push (stack * , int data); // for pushing the data
int pop (stack *); // for poping the data 
int main ()
{ stack s1;
init(&s1);
stack *p = &s1;
int i = 0;
char trial[] = "42*32-*";
int opd1 , opd2 , opd3;
while (trial[i] != '\0')
{
switch(trial[i])
{
	case '+' :
	    opd1 = pop(&s1);
	    opd2 = pop(&s1);
	    opd3 = opd1 + opd2;
	    push(&s1,opd3);
	    break;
	case '-' :
		opd1 = pop(&s1);
	    opd2 = pop(&s1);
	    opd3 = opd2 - opd1;
	    push(&s1,opd3);
	    break;
	case '*' :
		opd1 = pop(&s1);
	    opd2 = pop(&s1);
	    opd3 = opd1*opd2;
	    push(&s1,opd3);
	    break;
	default :
			int v = trial[i] - '0';   // imp concept for converting the char value to its numberical value 
			push(&s1,v);              // basically we are using the difference between the skcII value for getting the 
			break;		              // numerical value
}
printf("%d\n" , p->array[p->top]);
	i++;
}
printf("%d" ,p->array[p->top]);
	return 0;
}
void init (stack *sp)
{
sp->top = -1;
}
void push (stack *sp , int data)
{
if (sp->top == 9)
{
	printf("stack over flow");
	return ;
}
sp->top++;
sp->array[sp->top] = data;
}
int pop (stack *sp)
{ int data;
if (sp->top == -1)
{
	printf("stack underflow");
	return 79;
}
data = sp->array[sp->top];
sp->top--;
return data;
}
