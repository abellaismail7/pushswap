#include "checker.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

t_stack stack_wrap(int *arr, int cap, int len)
{
	t_stack st;

	st.arr = arr;
	st.len = cap;
	st.capacity = len;
	return st;
}

int is_sorted(t_stack st)
{
	int i;
	int last;

	i = 1;
	last = st.arr[0];

	while (i < st.len)
	{
		if (st.arr[i] > last)
			return 0;
		last = st.arr[i];
		i++;
	}
	return 1;
}

void ft_pushswap(t_data *data)
{
	int n;
	
	if(has_dup(&data->sta))
	{
		ft_putstrfd(2, "Error\n");
		return ;
	}
	while(1)
	{
		n = run_instra(data);
		if (n == 0 
			&& is_sorted(data->sta)
			&& data->stb.len == 0)
		{
			ft_putstrfd(1, "OK");
			break;
		}
		else if (n == 0)
		{
			ft_putstrfd(2, "KO");
			break;
		}
		else if (n == -1)
		{
			ft_putstrfd(2, "Error\n");
			return ;
		}
	}
	
}

int data_setup(int size, char **av)
{
	t_data data;

	data.print_inst = 0;
	data.sta = stack_wrap(av2int(av, size), size, size); // check dup 
	data.stb = stack_wrap(malloc(sizeof(int) * size), 0, size);
	if (data.sta.arr == 0 ||  data.stb.arr == 0)
	{
		ft_putstrfd(2, "Error\n");
		free(data.sta.arr);
		free(data.stb.arr);
		return 1;
	}
	ft_pushswap(&data);
	free(data.sta.arr);
	free(data.stb.arr);
	return 0;
}

int main(int ac, char **av)
{
	return (data_setup(ac - 1, av + 1));
}
