#include "checker.h"
#include "pushswap.h"
#include "stack.h"


int swapa(t_data *data)
{
	if(data->print_inst)
		ft_putstrfd(1, "sa\n");
	return instra_s(&(data->sta));
}
int swapb(t_data *data)
{
	if(data->print_inst)
		ft_putstrfd(1, "sb\n");
	return instra_s(&(data->stb));
}
int swapab(t_data *data)
{
	if(data->print_inst)
		ft_putstrfd(1, "ss\n");
	return swapa(data) || swapb(data);
}

int pusha(t_data *data)
{
	if(data->print_inst)
		ft_putstrfd(1, "pa\n");
	return instra_p(&data->sta, &data->stb);
}

int pushb(t_data *data)
{
	if(data->print_inst)
		ft_putstrfd(1, "pb\n");
	return instra_p(&data->stb, &data->sta);
}
