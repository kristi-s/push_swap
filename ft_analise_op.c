/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analise_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 00:27:27 by droslyn           #+#    #+#             */
/*   Updated: 2021/06/28 14:33:11 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_lst_take_content(t_list **ptr_lst, int i)
{
	t_list	*lst;

	lst = *ptr_lst;
	while (i > 0)
	{
		lst = lst->next;
		i--;
	}
	return (*(int *)lst->content);
}

static size_t	ft_find_count_ra(t_stacks *data, int num_b)
{
	t_list	*lst;
	t_list	*pre_lst;
	size_t	count_ra;

	count_ra = 0;
	pre_lst = ft_lstlast(data->stack_A);
	lst = data->stack_A;
	while (lst)
	{
		if (num_b < *(int *)lst->content && (num_b > *(int *)pre_lst->content \
			|| *(int *)pre_lst->content == data->max))
			break ;
		else
			count_ra++;
		pre_lst = lst;
		lst = lst->next;
	}
	return (count_ra);
}

static t_cmd	*ft_get_list_cmd(t_stacks *data, int i)
{
	t_cmd	*info_cmd;

	info_cmd = ft_init_info_cmd(data);
	info_cmd->rb = i;
	ft_rb_or_rrb(info_cmd);
	info_cmd->num_b = ft_lst_take_content(&data->stack_B, i);
	info_cmd->ra = ft_find_count_ra(data, info_cmd->num_b);
	ft_ra_or_rra(info_cmd);
	if (info_cmd->ra > 0 && info_cmd->rb > 0)
		ft_count_rr(info_cmd);
	if (info_cmd->rra > 0 && info_cmd->rrb > 0)
		ft_count_rrr(info_cmd);
	return (info_cmd);
}

size_t	ft_analise_op(t_stacks *data, int i)
{
	size_t	count;
	t_cmd	*info_cmd;

	info_cmd = ft_get_list_cmd(data, i);
	count = ft_sum_cmd(info_cmd);
	free(info_cmd);
	return (count);
}

void	ft_do_push(t_stacks *data, int i)
{
	t_cmd	*info_cmd;

	info_cmd = ft_get_list_cmd(data, i);
	op_count_rotate_all(data, info_cmd->rr);
	op_count_reverse_rotate_all(data, info_cmd->rrr);
	op_count_rotate(&data->stack_A, info_cmd->ra, STACK_A);
	op_count_rotate(&data->stack_B, info_cmd->rb, STACK_B);
	op_count_reverse_rotate(&data->stack_A, info_cmd->rra, STACK_A);
	op_count_reverse_rotate(&data->stack_B, info_cmd->rrb, STACK_B);
	op_push(&data->stack_B, &data->stack_A, STACK_A);
	free(info_cmd);
}
