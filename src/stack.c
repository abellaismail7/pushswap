/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:19:36 by iait-bel          #+#    #+#             */
/*   Updated: 2021/12/26 14:19:36 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "pushswap.h"


void push(t_stack *st, int val)
{
	if (st->capacity <= st->len)
	{
		ft_putstrfd(2, "Stack is full: can't push\n");
	}
	st->arr[st->len] = val;
	st->len++;
}

int pop(t_stack *st)
{
	if (st->len == 0)
	{
		ft_putstrfd(2, "Stack is empty: can't pop\n");
		return 0;
	}
	st->len--;
	return st->arr[st->len];
}

void instra_s(t_stack *st)
{
	if (st->len <= 1)
		return ft_putstrfd(2, "Stack doesn't have enough elements to swap\n");
	swap(st->arr, st->len -1 , st->len - 2);
}

void instra_p(t_stack *st1, t_stack *st2)
{
	int n;

	n = pop(st2);
	if (st2->len == 0)
		return ;
	push(st1, n);	

}

void instra_r(t_stack *st)
{
	int len;

	len = st->len;
	while(len-- > 1)
	{
		swap(st->arr, len, len - 1);
	}
}

void instra_rr(t_stack *st)
{
    int i = 0;
	while(i < st->len -1)
	{
		swap(st->arr, i, i + 1);
		i++;
	}
}
