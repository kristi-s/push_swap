/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 09:06:00 by droslyn           #+#    #+#             */
/*   Updated: 2021/06/29 09:08:13 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_creat_stack_A(char *str, t_stacks *data, int i)
{
	int		*num;
	int		n;
	t_list	*new_list;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) || str[i] == '-')
		{
			n = ft_atoi(&str[i]);
			num = ft_new_int_content(n);
			new_list = ft_lstnew(num);
			if (!new_list)
				ft_error_and_exit();
			if (!data->stack_A)
				data->stack_A = new_list;
			else
				ft_lstadd_back(&data->stack_A, new_list);
			data->count++;
			while (ft_isdigit(str[i]) || str[i] == '-' )
				i++;
		}
		else
			i++;
	}
}
