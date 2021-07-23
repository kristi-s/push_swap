/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:04:37 by droslyn           #+#    #+#             */
/*   Updated: 2021/07/06 17:01:12 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_new_int_content(int n)
{
	int	*new_ptr;

	new_ptr = malloc(sizeof(int));
	if (!new_ptr)
		ft_error_and_exit();
	*new_ptr = n;
	return (new_ptr);
}

t_stacks	*ft_init_struct(void)
{
	t_stacks	*new_data;

	new_data = malloc(sizeof(t_stacks));
	if (!new_data)
		ft_error_and_exit();
	new_data->stack_A = NULL;
	new_data->stack_B = NULL;
	new_data->mid = 0;
	new_data->count = 0;
	new_data->arr = NULL;
	new_data->save_i = 0;
	new_data->min_count = 1;
	return (new_data);
}

t_cmd	*ft_init_info_cmd(t_stacks *data)
{
	t_cmd	*info_cmd;

	info_cmd = malloc(sizeof(t_cmd));
	if (!info_cmd)
		ft_error_and_exit();
	info_cmd->ra = 0;
	info_cmd->rb = 0;
	info_cmd->rra = 0;
	info_cmd->rrb = 0;
	info_cmd->rr = 0;
	info_cmd->rrr = 0;
	info_cmd->num_b = 0;
	info_cmd->size_b = ft_lstsize(data->stack_B);
	info_cmd->size_a = ft_lstsize(data->stack_A);
	return (info_cmd);
}

void	ft_find_start_A(t_stacks *data)
{
	size_t	size_a;
	t_list	*lst;

	if (*(int *)(data->stack_A->content) != data->min)
	{
		data->i = 0;
		lst = data->stack_A;
		size_a = ft_lstsize(data->stack_A);
		while (lst && *(int *)(lst->content) != data->min)
		{
			lst = lst->next;
			data->i++;
		}
		if (data->i <= size_a - data->i)
			op_count_rotate(&data->stack_A, data->i, 1);
		else
			op_count_reverse_rotate(&data->stack_A, size_a - data->i, 1);
	}
}

void	ft_sort_three(t_stacks *data)
{
	int	num_1;
	int	num_2;
	int	num_3;

	if (*(int *)data->stack_A->content == data->max)
		op_rotate(&data->stack_A, STACK_A);
	op_count_push(data, data->count - 3, STACK_B);
	num_1 = *(int *)data->stack_A->content;
	num_2 = *(int *)data->stack_A->next->content;
	num_3 = *(int *)data->stack_A->next->next->content;
	if (num_1 > num_2 && num_1 > num_3)
	{
		op_rotate(&data->stack_A, STACK_A);
		if (num_2 > num_3)
			op_swap(&data->stack_A, STACK_A);
	}
	else if (num_1 < num_2 && num_1 < num_3 && num_2 > num_3)
	{
		op_swap(&data->stack_A, STACK_A);
		op_rotate(&data->stack_A, STACK_A);
	}
	else if (num_3 < num_2 && num_3 < num_1 && num_2 > num_1)
		op_reverse_rotate(&data->stack_A, STACK_A);
	else if (num_3 > num_2 && num_3 > num_1 && num_1 > num_2)
		op_swap(&data->stack_A, STACK_A);
}
