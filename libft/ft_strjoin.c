/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:45:02 by droslyn           #+#    #+#             */
/*   Updated: 2021/07/02 13:55:31 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptrstr;
	char	*str;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	ptrstr = malloc((len + 1) * (sizeof(char)));
	if (!ptrstr)
		return (0);
	str = ptrstr;
	while (*s1)
	{
		*ptrstr = *s1;
		s1++;
		ptrstr++;
	}
	while (*s2)
	{
		*ptrstr = *s2;
		s2++;
		ptrstr++;
	}
	*ptrstr = '\0';
	return (str);
}
