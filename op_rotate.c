//
// Created by Кристина Смирнова on 26.06.2021.
//

#include "push_swap.h"

void	op_rotate(t_list**	lst, int flag_write)
{
	t_list* lst_1;
	t_list* lst_2;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	lst_1 = *lst;
	lst_2 = lst_1->next;
	lst_1->next = NULL;
	*lst = lst_2;
	ft_lstadd_back(lst, lst_1);
	if (flag_write == STACK_A)
		write(1, "ra\n", 3);
	else if (flag_write == STACK_B)
		write(1, "rb\n", 3);

}

void	op_rotate_all(t_list**	lst_A, t_list**	lst_B, int flag_write)
{
	op_rotate(lst_A, NO_WRITE);
	op_rotate(lst_B, NO_WRITE);
	if (flag_write == WRITE)
		write(1, "rr\n", 3);

}

void	op_reverse_rotate(t_list**	lst, int flag_write)
{
	t_list*	lst_last;
	t_list* lst_tmp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	lst_last = ft_lstlast(*lst);
	lst_tmp = *lst;
	while (lst_tmp->next != lst_last)
	{
		lst_tmp = lst_tmp->next;
	}
	lst_tmp->next = NULL;
	ft_lstadd_front(lst, lst_last);
	if (flag_write == STACK_A)
		write(1, "rra\n", 4);
	else if (flag_write == STACK_B)
		write(1, "rrb\n", 4);
}

void	op_reverse_rotate_all(t_list**	lst_A, t_list**	lst_B, int flag_write)
{
	op_reverse_rotate(lst_A, NO_WRITE);
	op_reverse_rotate(lst_B, NO_WRITE);
	if (flag_write == WRITE)
		write(1, "rrr\n", 4);
}

