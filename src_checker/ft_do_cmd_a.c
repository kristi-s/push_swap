/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_cmd_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:26:33 by droslyn           #+#    #+#             */
/*   Updated: 2021/07/06 16:43:23 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_stacks *data)
{
	if (!data->stack_A || !data->stack_A->next)
	{
		data->save_i = 1;
		return ;
	}
	op_rotate(&data->stack_A, NO_WRITE);
}

void	ft_rra(t_stacks *data)
{
	if (!data->stack_A || !data->stack_A->next)
	{
		data->save_i = 1;
		return ;
	}
	op_reverse_rotate(&data->stack_A, NO_WRITE);
}

void	ft_pa(t_stacks *data)
{
	if (!data->stack_B)
	{
		data->save_i = 1;
		return ;
	}
	op_push(&data->stack_B, &data->stack_A, NO_WRITE);
}

void	ft_sa(t_stacks *data)
{
	if (!data->stack_A || !data->stack_A->next)
	{
		data->save_i = 1;
		return ;
	}
	op_swap(&data->stack_A, NO_WRITE);
}
