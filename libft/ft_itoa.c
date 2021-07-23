/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:04:46 by droslyn           #+#    #+#             */
/*   Updated: 2021/07/02 13:19:06 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_int(int num)
{
	unsigned int	nm;
	int				size;

	size = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		size++;
		nm = -num;
	}
	else
		nm = num;
	while (nm)
	{
		nm = nm / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int				size;
	unsigned int	number;
	char			*ptr;

	size = ft_len_int(n);
	if (n < 0)
		number = -n;
	else
		number = n;
	ptr = malloc((size + 1) * sizeof(char));
	if (!ptr)
		return (0);
	if (n < 0)
		*ptr = '-';
	else if (n == 0)
		*ptr = '0';
	*(ptr + size) = '\0';
	while (number)
	{
		size--;
		*(ptr + size) = (number % 10) + '0';
		number = number / 10;
	}
	return (ptr);
}
