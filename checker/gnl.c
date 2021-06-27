//
// Created by Кристина Смирнова on 26.06.2021.
//
#include "../push_swap.h"

static int		ft_append_buf(char **line, char *buf)
{
	char		*tmp;
	int			i;

	i = 0;
	if (!(tmp = malloc(ft_strlen(*line) + 2)))
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

int				ft_read_line(int fd, char **line)
{
	static char	buf[2];
	int			n;

	if (fd < 0 || !line || !(*line = malloc(1)))
		return (-1);
	(*line)[0] = '\0';
	while ((n = read(fd, buf, 1)) > 0)
	{
		if (buf[0] == '\n')
			return (1);
		if (ft_append_buf(line, buf) == -1)
			return (-1);
	}
	if (n < 0)
		return (-1);
	return (0);
}
