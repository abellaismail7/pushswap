#include "pushswap.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void iquicksort(int *arr, int *iarr, int left);
int *incarr(int size);

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
	int i;
	
	i = 0;
	while(1)
	{
		if (is_sorted(data->sta))
		{
			pushback(data);
			break;
		}
		nextinstra(data); 
		i++;
	}
	
}

int data_setup(int size, char **av)
{
	t_data data;
	int *arr;

	arr = av2int(av, size);
	//int i = 0;
	//while( i < size)
	//{
	//	printf("%d - ", arr[i]);
	//	i++;
	//}
	data.sta = stack_wrap(av2int(av, size), size, size); // arr clone
	data.stb = stack_wrap(malloc(sizeof(int) * size), 0, size);
	data.arrpos = stack_wrap(incarr(size),size, size);
	if (data.sta.arr == 0 ||  data.stb.arr == 0)
	{
		free(data.sta.arr);
		free(data.stb.arr);
		return 1;
	}
	iquicksort(arr, data.arrpos.arr, size);
	free(arr);
	ft_pushswap(&data);
	free(data.sta.arr);
	free(data.stb.arr);
	return 0;
}

int main(int ac, char **av)
{
	return (data_setup(ac - 1, av + 1));
}
