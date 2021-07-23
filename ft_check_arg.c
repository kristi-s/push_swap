/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:40:17 by droslyn           #+#    #+#             */
/*   Updated: 2021/07/01 21:07:16 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_arg(char *str, int i, int count_num, char *ptr)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != ' ')
			return (1);
		if (ft_isdigit(str[i]))
		{
			if (count_num == 0)
			{
				if (i > 0 && str[i - 1] == '-')
					ptr = &str[i - 1];
				else
					ptr = &str[i];
			}
			count_num++;
			if (count_num == 10)
			{
				if (ft_atoi(ptr) == -1 || ft_atoi(ptr) == 0)
					return (1);
			}
		}
		if (str[i] == ' ')
			count_num = 0;
		i++;
	}
	return (0);
}

int	ft_check_repeat(t_stacks *data)
{
	int	i;

	i = 0;
	while (i < data->count - 1)
	{
		if (data->arr[i] == data->arr[i + 1])
			ft_error_and_exit();
		i++;
	}
	return (0);
}
