/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_mid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:32:01 by droslyn           #+#    #+#             */
/*   Updated: 2021/07/01 16:55:51 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_quick_sort(int *arr, int count, int i)
{
	int	i_end;
	int	mid;
	int	tmp;

	i_end = count - 1;
	mid = arr[count / 2];
	while (i <= i_end)
	{
		while (arr[i] < mid)
			i++;
		while (arr[i_end] > mid)
			i_end--;
		if (i <= i_end)
		{
			tmp = arr[i];
			arr[i] = arr[i_end];
			arr[i_end] = tmp;
			i++;
			i_end--;
		}
		if (i_end > 0)
			ft_quick_sort(arr, i_end + 1, 0);
		if (i < count)
			ft_quick_sort(&arr[i], count - i, 0);
	}
}

static void	ft_init_array(t_stacks *data)
{
	int		*new_arr;
	t_list	*lst;

	new_arr = ft_calloc(data->count, sizeof(int));
	if (!new_arr)
		ft_error_and_exit();
	data->arr = new_arr;
	lst = data->stack_A;
	while (lst)
	{
		*new_arr = *(int *)lst->content;
		lst = lst->next;
		new_arr++;
	}
}

int	ft_check_sort(t_list **lst_stack)
{
	t_list	*lst;
	int		num;
	int		num_next;

	lst = *lst_stack;
	if (lst && !lst->next)
		return (1);
	while (lst->next)
	{
		num = *(int *)lst->content;
		num_next = *(int *)lst->next->content;
		if (num_next <= num)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	ft_find_mid(t_stacks *data)
{
	int	half_count;

	ft_init_array(data);
	if (ft_check_sort(&data->stack_A))
		exit(0);
	ft_quick_sort(data->arr, data->count, 0);
	ft_check_repeat(data);
	if (data->count % 2 == 0)
		half_count = data->count / 2 - 1;
	else
		half_count = data->count / 2;
	data->mid = data->arr[half_count];
	data->min = data->arr[0];
	data->max = data->arr[data->count - 1];
	data->pre_max = data->arr[data->count - 2];
}
