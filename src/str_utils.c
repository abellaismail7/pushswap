#include <unistd.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return i;
}


void ft_putstrfd(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}
