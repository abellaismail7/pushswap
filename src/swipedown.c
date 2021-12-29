#include "stack.h"
#include "common.h"

int swipedowna(t_data *data)
{
	if(data->print_inst)
		ft_putstrfd(1, "rra\n");
	return instra_rr(&data->sta);
}

int swipedownb(t_data *data)
{
	if(data->print_inst)
		ft_putstrfd(1, "rrb\n");
	return instra_rr(&data->stb);
}

int swipedown(t_data *data)
{
	if(data->print_inst)
		ft_putstrfd(1, "rrr\n");
	return swipedowna(data) || swipedownb(data);
}

