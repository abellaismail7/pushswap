
#include "common.h"
#include "stack.h"

int swipeupa(t_data *data)
{
	if(data->print_inst)
		ft_putstrfd(1, "ra\n");
	return instra_r(&data->sta);
}

int swipeupb(t_data *data)
{
	if(data->print_inst)
		ft_putstrfd(1, "rb\n");
	return instra_r(&data->stb);
}

int swipeup(t_data *data)
{
	if(data->print_inst)
		ft_putstrfd(1, "rr\n");
	return instra_r(&data->sta) || instra_r(&data->stb);
}

