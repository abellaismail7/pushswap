#include "pushswap.h"
#include "stack.h"

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

int pushb(t_data *data)
{
	ft_putstrfd(1, "pb\n");
	instra_p(&data->stb, &data->sta);
	return 1;
}

int pusha(t_data *data)
{
	ft_putstrfd(1, "pa\n");
	instra_p(&data->sta, &data->stb);
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
	i = 0;
	while(i < st.len)
	{
		if (st.arr[i] < st.arr[mpos[0]])
		{
			mpos[0] = i;
		}
		i++;
	}
}

int nextinstra(t_data *data)
{
	int mpos[2];
	
	find_min(data->sta, mpos);
	bringtoTop(&data->sta, mpos[0], "a\n");
	pushb(data);
	return 1;
}
