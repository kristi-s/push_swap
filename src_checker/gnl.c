/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:34:40 by droslyn           #+#    #+#             */
/*   Updated: 2021/07/02 14:37:56 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_append_buf(char **line, char *buf)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(ft_strlen(*line) + 2);
	if (!tmp)
		return (-1);
	while ((*line)[i])
	{
		tmp[i] = (*line)[i];
		i++;
	}
	tmp[i] = buf[0];
	tmp[i + 1] = '\0';
	free(*line);
	*line = tmp;
	return (1);
}

int	ft_read_line(int fd, char **line)
{
	static char	buf[2];
	int			n;

	if (fd < 0 || !line)
		return (-1);
	*line = malloc(1);
	if (!*line)
		return (-1);
	(*line)[0] = '\0';
	n = read(fd, buf, 1);
	while (n > 0)
	{
		if (buf[0] == '\n')
			return (1);
		if (ft_append_buf(line, buf) == -1)
			return (-1);
		n = read(fd, buf, 1);
	}
	if (n < 0)
		return (-1);
	return (0);
}
