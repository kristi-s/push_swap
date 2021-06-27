//
// Created by Кристина Смирнова on 26.06.2021.
//

#include "push_swap.h"

void 	op_count_rotate(t_list** lst, int count, int flag_write)
{
	while (count > 0)
	{
		op_rotate(lst, flag_write);
		count--;
	}
}

void 	op_count_reverse_rotate(t_list** lst, int count, int flag_write)
{
	while (count > 0)
	{
		op_reverse_rotate(lst, flag_write);
		count--;
	}
}

void 	op_count_rotate_all(t_stacks* data, int count)
{
	while (count > 0)
	{
		op_rotate_all(&data->stack_A, &data->stack_B, WRITE);
		count--;
	}
}

void 	op_count_reverse_rotate_all(t_stacks* data, int count)
{
	while (count > 0)
	{
		op_reverse_rotate_all(&data->stack_A, &data->stack_B, WRITE);
		count--;
	}
}
