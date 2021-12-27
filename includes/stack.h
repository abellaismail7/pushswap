#ifndef STACK_H
#define STACK_H
typedef struct s_stack
{
	int len;
	int capacity;
	int *arr;
}	t_stack;


void push(t_stack *st, int val);
int pop(t_stack *st);
void instra_s(t_stack *st);
void instra_p(t_stack *st1, t_stack *st2);
void instra_r(t_stack *st);
void instra_rr(t_stack *st);

#endif // !STACK_H

