/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_cmd_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:28:19 by droslyn           #+#    #+#             */
/*   Updated: 2021/07/06 16:43:35 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rb(t_stacks *data)
{
	if (!data->stack_B || !data->stack_B->next)
	{
		data->save_i = 1;
		return ;
	}
	op_rotate(&data->stack_B, NO_WRITE);
}

void	ft_rrb(t_stacks *data)
{
	if (!data->stack_B || !data->stack_B->next)
	{
		data->save_i = 1;
		return ;
	}
	op_reverse_rotate(&data->stack_B, NO_WRITE);
}

void	ft_pb(t_stacks *data)
{
	if (!data->stack_A)
	{
		data->save_i = 1;
		return ;
	}
	op_push(&data->stack_A, &data->stack_B, NO_WRITE);
}

void	ft_sb(t_stacks *data)
{
	if (!data->stack_B || !data->stack_B->next)
	{
		data->save_i = 1;
		return ;
	}
	op_swap(&data->stack_B, NO_WRITE);
}
