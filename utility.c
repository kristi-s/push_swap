//
// Created by Donny Roslyn on 6/13/21.
//

#include "push_swap.h"

int*	ft_new_int_content(int n)
{
	int* new_ptr;
	new_ptr = malloc(sizeof(int));
	if (!new_ptr)
	{
		ft_error();
		exit(1);
	}
	*new_ptr = n;
	return new_ptr;
}

t_stacks*	ft_init_struct()
{
	t_stacks* new_data;

	new_data = malloc(sizeof(t_stacks));
	if (!new_data)
	{
		ft_error();
		exit(1);
	}
	new_data->stack_A = NULL;
	new_data->stack_B = NULL;
	new_data->mid_1 = 0;
	new_data->mid_2 = 0;
	new_data->count = 0;
	new_data->arr = NULL;
	return new_data;
}
