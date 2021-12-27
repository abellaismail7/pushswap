#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include "stack.h"
typedef struct s_data
{
	t_stack sta;	
	t_stack stb;	
	t_stack arrpos;
	int size;
} t_data;

int ft_strlen(char *str);
void ft_putstrfd(int fd, char *str);
int *av2int(char **av, int size);
void swap(int *arr, int a, int b);
int nextinstra(t_data *data);
int pushback(t_data *data);

#endif // !PUSHSWAP_H
