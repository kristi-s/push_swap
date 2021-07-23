/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_body.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 23:53:01 by droslyn           #+#    #+#             */
/*   Updated: 2021/07/06 17:01:44 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_divide_stack(t_stacks *data, int num_a, int first_el)
{
	size_t	size;

	num_a = *(int *)data->stack_A->content;
	if (num_a == data->max)
	{
		op_rotate(&data->stack_A, STACK_A);
		num_a = *(int *)data->stack_A->content;
	}
	size = ft_lstsize(data->stack_A);
	first_el = num_a;
	while (size > 2)
	{
		if (num_a < data->pre_max)
		{
			op_push(&data->stack_A, &data->stack_B, STACK_B);
			if (num_a != first_el && num_a < data->mid)
				op_rotate(&data->stack_B, STACK_B);
		}
		else
			op_rotate(&data->stack_A, STACK_A);
		num_a = *(int *)data->stack_A->content;
		size = ft_lstsize(data->stack_A);
	}
	if (num_a == data->max)
		op_rotate(&data->stack_A, STACK_A);
}

static void	ft_save(t_stacks *data, size_t count, size_t i)
{
	data->min_count = count;
	data->save_i = i;
}

static void	ft_sort_stack(t_stacks *data, size_t i, size_t size_b)
{
	size_t	count;

	data->min_count = 1;
	size_b = ft_lstsize(data->stack_B);
	while ((i < (size_b / 2)) && (data->min_count > i))
	{
		count = ft_analise_op(data, i);
		if (count == 0)
		{
			op_push(&data->stack_B, &data->stack_A, STACK_A);
			return ;
		}
		if (i == 0 || count < data->min_count)
			ft_save(data, count, i);
		i++;
	}
	i = size_b - 1;
	while ((i > (size_b / 2)) && (data->min_count > (size_b - i)))
	{
		count = ft_analise_op(data, i);
		if (count < data->min_count)
			ft_save(data, count, i);
		i--;
	}
	ft_do_push(data, data->save_i);
}

void	ft_main_body(int argc, char **argv)
{
	int			i;
	t_stacks	*data;

	data = ft_init_struct();
	i = 1;
	while (i < argc)
	{
		if (ft_check_arg(argv[i], 0, 0, NULL))
			ft_error_and_exit();
		ft_creat_stack_A(argv[i], data, 0);
		i++;
	}
	ft_find_mid(data);
	if (data->count > 2 && data->count <= 5)
		ft_sort_three(data);
	else
		ft_divide_stack(data, 0, 0);
	while (data->stack_B)
		ft_sort_stack(data, 0, 0);
	ft_find_start_A(data);
	ft_free(data);
}
