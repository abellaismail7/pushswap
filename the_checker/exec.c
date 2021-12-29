#include <unistd.h>
#include "pushswap.h"
#include "common.h"
#include "stack.h"


int has_dup(t_stack * st)
{
	int i;
	int j;

	i = 0;
	while(i < st->len)
	{
		j = i + 1;
		while(j < st->len)
		{
			if (st->arr[i] == st->arr[j])
				return 1;
			j++;
		}
		i++;
	}

	return 0;
}

int getnextline(int fd, char *str)
{
	char buf;
	int n;
	int i;

	i = 0;
	str[0] = 0;
	while(1)
	{
		n = read(fd, &buf, 1);
		if (n == 0 || n == -1)
		{
			str[i] = 0;
			return n;
		}
		str[i] = buf;
		if(i++ == 3 || buf == '\n')
		{
			str[i] = 0;
			return 1;
		}
	}
}

int run_instra(t_data *data)
{
	char str[5];
	int i;

	i = getnextline(STDIN_FILENO, str);

	if (i == -1)
		return -1;

	if (i == 0 && str[i] == 0)
		return 0;
	
	if (ft_strcmp(str, "sa\n") == 0)
		return swapa(data);
	else if (ft_strcmp(str, "sb\n") == 0)
		return swapb(data);
	else if (ft_strcmp(str, "ss\n") == 0)
		return swapab(data);

	else if (ft_strcmp(str, "pa\n") == 0)
		return pusha(data);
	else if (ft_strcmp(str, "pb\n") == 0)
		return pushb(data);

	else if (ft_strcmp(str, "ra\n") == 0)
		return swipeupa(data);
	else if (ft_strcmp(str, "rb\n") == 0)
		return swipeupb(data);
	else if (ft_strcmp(str, "rr\n") == 0)
		return swipeup(data);

	else if (ft_strcmp(str, "rra\n") == 0)
		return swipedowna(data);
	else if (ft_strcmp(str, "rrb\n") == 0)
		return swipedownb(data);
	else if (ft_strcmp(str, "rr\n") == 0)
		return swipedown(data);
	else
		return -1;
}
