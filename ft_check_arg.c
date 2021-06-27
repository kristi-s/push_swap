//
// Created by Donny Roslyn on 6/13/21.
//

#include "push_swap.h"

int		ft_check_arg(char *str)
{
	int i = 0;
	int count_num = 0;
	char*	ptr;

	// TODO write ft_check
	while(str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != ' ')
			return 1;
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
					return 1;
			}
		}
		if (str[i] == ' ')
			count_num = 0;
		i++;
	}
	return 0; //if OK
}

int 	ft_check_repeat(t_stacks* data)
{
	size_t i = 0;

	while (i < data->count - 1)
	{
		if (data->arr[i] == data->arr[i + 1])
		{
			ft_error();
			exit(1);
		}
		i++;
	}
	return 0;
}