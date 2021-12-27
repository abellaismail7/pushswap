#include<stdlib.h>

int	is_space(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	ft_atoi(char *str)
{
	int	sign;
	int	res;

	sign = -1;
	while (is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res *= 10;
		res -= *str - '0';
		str++;
	}
	return (res * sign);
}

int *incarr(int size)
{
	int *arr;
	int i;

	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		return NULL;
	i  = 0;
	while (i < size)
	{
		arr[i] = i;
		i++;
	}
	return arr;
}

int *av2int(char **av, int size)
{
	int	*arr;
	int i;

	arr = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		arr[size - i - 1] = ft_atoi(av[i]);
		i++;
	}

	return arr;
}

void swap(int *arr, int i1, int i2)
{
	int tmp = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = tmp;
}

void iquicksort(int *arr, int *iarr, int left)
{
	int last;
	int right;
	int index;

	if (left <= 0)
		return ;
	last = arr[left - 1];
	index = 0;
	right = 0;
	while (right < left)
	{
		if(arr[right] <= last)
		{
			swap(arr, index, right);
			swap(iarr, index, right);
			index++;
		}
		right++;
	}
	iquicksort(arr, iarr, index - 1);
	iquicksort(arr + index + 1, iarr + index + 1, left - index - 1);
}
