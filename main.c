//
// Created by Donny Roslyn on 6/13/21.
//
#include "push_swap.h"


int		main(int argc, char **argv)
{
	count_steps = 0;
	if (argc > 1)
		ft_creat_stack_new(argv[1]);
	else
		return (ft_error());

	printf("steps = %d\n", count_steps);
}

