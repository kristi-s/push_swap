//
// Created by Donny Roslyn on 6/13/21.
//

#include "push_swap.h"

void	op_swap(t_list** lst, int flag_write)
{
	t_list*	lst_end;
	t_list* lst_1;
	t_list* lst_2;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	lst_1 = *lst;
	lst_2 = lst_1->next;
	lst_end = lst_2->next;
	lst_1->next = lst_end;
	lst_2->next = lst_1;
	*lst = lst_2;
	if (flag_write == STACK_A)
		write(1, "sa\n", 3);
	else if (flag_write == STACK_B)
		write(1, "sb\n", 3);
}

void	op_swap_all(t_list**	lst_A, t_list**	lst_B, int flag_write)
{
	op_swap(lst_A, NO_WRITE);
	op_swap(lst_B, NO_WRITE);
	if (flag_write == WRITE)
		write(1, "rr\n", 3);
}

void 	op_push(t_list**	lst_A, t_list**	lst_B, int flag_write) // from A to B
{
	t_list*	lst_end;
	t_list* lst_1;

	if (!lst_A || !lst_B || !*lst_A)
		return ;
	lst_1 = *lst_A;
	lst_end = lst_1->next;
	*lst_A = lst_end;
	ft_lstadd_front(lst_B, lst_1);
	if (flag_write == STACK_A)
		write(1, "pa\n", 3);
	else if (flag_write == STACK_B)
		write(1, "pb\n", 3);
}



