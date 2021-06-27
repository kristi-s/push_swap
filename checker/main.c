//
// Created by Кристина Смирнова on 26.06.2021.
//

#include "../push_swap.h"

int		main(int argc, char **argv)
{
	if (argc > 1)
		ft_creat_stack_checker(argv[1]);
	else
		return (ft_error());
}

void 	ft_creat_stack_checker(char *str)
{
	t_stacks* data;
	int			n;
	char*		line;

	if (ft_check_arg(str))
	{
		ft_error();
		return ;
	}

	data = ft_init_struct();
	ft_creat_stack_A(str, data);

	while ((n = ft_read_line(1, &line)) > 0)
		ft_parse_cmd(line, data);
}


void 	ft_parse_cmd(char* line, t_stacks* data)
{
	if (ft_strcmp(line, "sa\n"))
	{
		op_swap(&data->stack_A, STACK_A);
		free(line);
		return;
	}
	else if ()
}