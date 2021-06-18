//
// Created by Donny Roslyn on 6/13/21.
//
#include "push_swap.h"



void	ft_creat_stack(char *str)
{
	t_stacks* data;
	if (ft_check_arg(str))
	{
		ft_error();
		return ;
	}

	data = ft_init_struct();
	ft_creat_stack_A(str, data);
//	if (data->count > 5)
//		ft_find_mid(str, data);
//	TODO дописать сортировку если мало элементов


	ft_sort_stack(data);

//	proverka(data); // delete this !!!

}

void	ft_creat_stack_A(char *str, t_stacks* data)
{
	int	i;
	int* num;
	int	n;
	t_list* new_list;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) || str[i] == '-')
		{
			n = ft_atoi(&str[i]);
			num = ft_new_int_content(n);
			new_list = ft_lstnew(num);
			if (!new_list)
			{
				ft_error();
				exit(1);
			}
			if (!data->stack_A)
				data->stack_A = new_list;
			else
				ft_lstadd_back(&data->stack_A, new_list);
			data->count++;
			while(ft_isdigit(str[i]) || str[i] == '-')
				i++;
		}
		else
			i++;
	}
}