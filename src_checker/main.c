/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:38:39 by droslyn           #+#    #+#             */
/*   Updated: 2021/07/06 16:33:30 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
		ft_creat_stack_checker(argc, argv);
	else
		return (0);
}

void	ft_creat_stack_checker(int argc, char **argv)
{
	int			n;
	char		*line;
	int			i;
	t_stacks	*data;

	data = ft_init_struct();
	i = 1;
	while (i < argc)
	{
		if (ft_check_arg(argv[i], 0, 0, NULL))
			ft_error_and_exit();
		ft_creat_stack_A(argv[i], data, 0);
		i++;
	}
	ft_find_mid(data);
	n = ft_read_line(0, &line);
	while (n > 0)
	{
		ft_parse_cmd(line, data);
		free(line);
		n = ft_read_line(0, &line);
	}
	if (data->save_i || !ft_check_sort(&data->stack_A) || data->stack_B)
		ft_return(KO);
	ft_return(OK);
}

void	ft_parse_cmd(char *line, t_stacks *data)
{
	if (!ft_strcmp(line, "ra"))
		ft_ra(data);
	else if (!ft_strcmp(line, "rb"))
		ft_rb(data);
	else if (!ft_strcmp(line, "rr"))
		ft_rr(data);
	else if (!ft_strcmp(line, "rra"))
		ft_rra(data);
	else if (!ft_strcmp(line, "rrb"))
		ft_rrb(data);
	else if (!ft_strcmp(line, "rrr"))
		ft_rrr(data);
	else if (!ft_strcmp(line, "pa"))
		ft_pa(data);
	else if (!ft_strcmp(line, "pb"))
		ft_pb(data);
	else if (!ft_strcmp(line, "sa"))
		ft_sa(data);
	else if (!ft_strcmp(line, "sb"))
		ft_sb(data);
	else if (!ft_strcmp(line, "ss"))
		ft_ss(data);
	else
		ft_error_and_exit();
}
