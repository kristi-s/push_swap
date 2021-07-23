/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:30:25 by droslyn           #+#    #+#             */
/*   Updated: 2021/07/02 20:12:24 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

void	ft_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_content(void *content)
{
	free(content);
}

void	ft_free(t_stacks *data)
{
	free(data->arr);
	ft_lstclear(&data->stack_A, ft_free_content);
	free(data);
}
