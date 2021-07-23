/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:03:02 by droslyn           #+#    #+#             */
/*   Updated: 2021/07/02 14:21:17 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_find_start(char const *s, unsigned int start)
{
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	return (start);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr_substr;
	char	*str;
	char	*sub;
	size_t	len_str;

	if (!s)
		return (0);
	start = ft_find_start(s, start);
	str = (char *)s + start;
	len_str = ft_strlen(str);
	if (len < len_str)
		len_str = len;
	ptr_substr = malloc((len_str + 1) * sizeof(char));
	if (!ptr_substr)
		return (0);
	sub = ptr_substr;
	while (len_str)
	{
		*ptr_substr = *str;
		ptr_substr++;
		str++;
		len_str--;
	}
	*ptr_substr = '\0';
	return (sub);
}
