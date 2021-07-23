/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_few_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:55:40 by droslyn           #+#    #+#             */
/*   Updated: 2021/07/01 21:17:23 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_count_rotate(t_list **lst, int count, int flag_write)
{
	while (count > 0)
	{
		op_rotate(lst, flag_write);
		count--;
	}
}

void	op_count_reverse_rotate(t_list **lst, int count, int flag_write)
{
	while (count > 0)
	{
		op_reverse_rotate(lst, flag_write);
		count--;
	}
}

void	op_count_rotate_all(t_stacks *data, int count)
{
	while (count > 0)
	{
		op_rotate_all(&data->stack_A, &data->stack_B, WRITE);
		count--;
	}
}

void	op_count_reverse_rotate_all(t_stacks *data, int count)
{
	while (count > 0)
	{
		op_reverse_rotate_all(&data->stack_A, &data->stack_B, WRITE);
		count--;
	}
}

void	op_count_push(t_stacks *data, int count, int flag_write)
{
	while (count > 0)
	{
		if (flag_write == STACK_A)
			op_push(&data->stack_B, &data->stack_A, STACK_A);
		else if (flag_write == STACK_B)
			op_push(&data->stack_A, &data->stack_B, STACK_B);
		count--;
	}
}
