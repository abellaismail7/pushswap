#include "pushswap.h"
#include "stack.h"
#include "common.h"

int bringtoTop(t_stack *st, int pos, char * str)
{
	int mv;

	if (pos == st->len - 1)
		return 0;
	if(pos + 2 == st->len)
	{
		ft_putstrfd(1, "s");
		ft_putstrfd(1, str);
		instra_s(st);
		return 1;

	}
	if (pos >= st->len / 2)
	{
		mv = st->len - pos - 1;
		while(mv--)
		{
			ft_putstrfd(1, "r");
			ft_putstrfd(1, str);
			instra_r(st);
		}
	}
	else
	{
		mv = pos + 1;
		while(mv--)
		{
			ft_putstrfd(1, "rr");
			ft_putstrfd(1, str);
			instra_rr(st);
		}
	}
	return 1;
}

int pushback(t_data *data)
{
	int i;
	
	i = 0;
	while (data->stb.len)
	{
		pusha(data);
		i++;
	}
	return i;
}

void find_min(t_stack st, int mpos[])
{
	int i;
	mpos[0] = 0;
	mpos[1] = 0;
	i = 0;
	while(i < st.len)
	{
		if (st.arr[i] < st.arr[mpos[0]])
		{
			mpos[1] = mpos[0];
			mpos[0] = i;
		}
		else if (st.arr[i] < st.arr[mpos[1]])
			mpos[1] = i;
		i++;
	}
}

int min(int a, int b)
{
	if (a > b)
		return b;
	return a;
}

#include <stdio.h>

int nextinstra(t_data *data)
{
	int mpos[2];
	int dis[2];

	find_min(data->sta, mpos);
	dis[0] = min(mpos[0] + 1, data->sta.len - mpos[0]);
	dis[1] = min(mpos[1] + 1, data->sta.len - mpos[1]);
	if (dis[0] < dis[1] || mpos[1] == 0)
	{
		bringtoTop(&data->sta, mpos[0], "a\n");
		pushb(data);
	}
	else
	{
		bringtoTop(&data->sta, mpos[1], "a\n");
		pushb(data);
		find_min(data->sta, mpos);
		bringtoTop(&data->sta, mpos[0], "a\n");
		pushb(data);
		swapb(data);
	}
	return 1;
}
