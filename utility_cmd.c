/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:59:06 by droslyn           #+#    #+#             */
/*   Updated: 2021/06/28 12:06:44 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb_or_rrb(t_cmd *info_cmd)
{
	if (info_cmd->rb > (info_cmd->size_b - info_cmd->rb))
	{
		info_cmd->rrb = info_cmd->size_b - info_cmd->rb;
		info_cmd->rb = 0;
	}
}

void	ft_ra_or_rra(t_cmd *info_cmd)
{
	if (info_cmd->ra > (info_cmd->size_a - info_cmd->ra))
	{
		info_cmd->rra = info_cmd->size_a - info_cmd->ra;
		info_cmd->ra = 0;
	}
}

void	ft_count_rr(t_cmd *info_cmd)
{
	if (info_cmd->ra > info_cmd->rb)
	{
		info_cmd->rr = info_cmd->rb;
		info_cmd->rb = 0;
		info_cmd->ra = info_cmd->ra - info_cmd->rr;
	}
	else
	{
		info_cmd->rr = info_cmd->ra;
		info_cmd->ra = 0;
		info_cmd->rb = info_cmd->rb - info_cmd->rr;
	}
}

void	ft_count_rrr(t_cmd *info_cmd)
{
	if (info_cmd->rra > info_cmd->rrb)
	{
		info_cmd->rrr = info_cmd->rrb;
		info_cmd->rrb = 0;
		info_cmd->rra = info_cmd->rra - info_cmd->rrr;
	}
	else
	{
		info_cmd->rrr = info_cmd->rra;
		info_cmd->rra = 0;
		info_cmd->rrb = info_cmd->rrb - info_cmd->rrr;
	}
}

size_t	ft_sum_cmd(t_cmd *info_cmd)
{
	size_t	sum;

	sum = info_cmd->ra + info_cmd->rb + info_cmd->rr + info_cmd->rra + \
			info_cmd->rrb + info_cmd->rrr;
	return (sum);
}
