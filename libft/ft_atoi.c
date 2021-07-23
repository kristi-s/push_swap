/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:39:21 by droslyn           #+#    #+#             */
/*   Updated: 2021/07/02 13:11:45 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || \
			c == '\r')
		return (1);
	return (0);
}

static int	ft_more_int(int minus)
{
	if (minus > 0)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int	res;
	int				minus;
	int				i;

	res = 0;
	minus = 1;
	i = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -minus;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (i == 10 || (i == 9 && (((res * 10 + (*str - '0')) > 2147483648) || \
				((res * 10 + (*str - '0')) > 2147483647 && minus == 1))))
			return (ft_more_int(minus));
		res = res * 10 + (*str - '0');
		str++;
		i++;
	}
	return (minus * res);
}
