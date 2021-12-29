#ifndef COMMON_H
#define COMMON_H

#include "pushswap.h"
int swapa(t_data *data);
int swapb(t_data *data);
int swapab(t_data *data);

int pusha(t_data *data);
int pushb(t_data *data);

int swipeupa(t_data *data);
int swipeupb(t_data *data);
int swipeup(t_data *data);

int swipedowna(t_data *data);
int swipedownb(t_data *data);
int swipedown(t_data *data);

int instra_s(t_stack *st);
int instra_p(t_stack *st1, t_stack *st2);
int instra_r(t_stack *st);
int instra_rr(t_stack *st);

int	ft_strcmp(char *s1, char *s2);

t_stack clone_st(t_stack *st);
void iquicksort(int *arr, int *iarr, int left);
void ft_quicksort(int *arr, int left);

#endif // !COMMON_H
