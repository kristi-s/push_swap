/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:29:38 by droslyn           #+#    #+#             */
/*   Updated: 2021/07/06 16:43:11 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rr(t_stacks *data)
{
	if (!data->stack_B || !data->stack_B->next || \
		!data->stack_A || !data->stack_A->next)
	{
		data->save_i = 1;
		return ;
	}
	op_rotate_all(&data->stack_A, &data->stack_B, NO_WRITE);
}

void	ft_rrr(t_stacks *data)
{
	if (!data->stack_B || !data->stack_B->next || \
		!data->stack_A || !data->stack_A->next)
	{
		data->save_i = 1;
		return ;
	}
	op_reverse_rotate_all(&data->stack_A, &data->stack_B, NO_WRITE);
}

void	ft_ss(t_stacks *data)
{
	if (!data->stack_B || !data->stack_B->next || \
		!data->stack_A || !data->stack_A->next)
	{
		data->save_i = 1;
		return ;
	}
	op_swap_all(&data->stack_A, &data->stack_B, NO_WRITE);
}
