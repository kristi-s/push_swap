//
// Created by Donny Roslyn on 6/13/21.
//

//rra : reverse rotate a - shift down all elements of stack a by 1. The last element
//becomes the first one.

//rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
//becomes the first one.

//rrr : rra and rrb at the same time.

#include "push_swap.h"

void	op_swap(t_list**	lst)
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
}

void	op_swap_all(t_list**	lst_A, t_list**	lst_B)
{
	op_swap(lst_A);
	op_swap(lst_B);
}

void 	op_push(t_list**	lst_A, t_list**	lst_B) // from A to B
{
	t_list*	lst_end;
	t_list* lst_1;
	t_list* lst_2;

	if (!lst_A || !lst_B || !*lst_A)
		return ;
	lst_1 = *lst_A;
	lst_end = lst_1->next;
	*lst_A = lst_end;
	ft_lstadd_front(lst_B, lst_1);
}

void	op_rotate(t_list**	lst)
{
	t_list*	lst_end;
	t_list* lst_1;
	t_list* lst_2;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	lst_1 = *lst;
	lst_2 = lst_1->next;
	lst_1->next = NULL;
	*lst = lst_2;
	ft_lstadd_back(lst, lst_1);
}

void	op_rotate_all(t_list**	lst_A, t_list**	lst_B)
{
	op_rotate(lst_A);
	op_rotate(lst_B);
}

void	op_reverse_rotate(t_list**	lst)
{
	t_list*	lst_last;
	t_list* lst_1;
	t_list* lst_tmp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	lst_1 = *lst;
	lst_last = ft_lstlast(*lst);
	lst_tmp = *lst;
	while (lst_tmp->next != lst_last)
	{
		lst_tmp = lst_tmp->next;
	}
	lst_tmp->next = NULL;
	ft_lstadd_front(lst, lst_last);
}

void	op_reverse_rotate_all(t_list**	lst_A, t_list**	lst_B)
{
	op_reverse_rotate(lst_A);
	op_reverse_rotate(lst_B);
}




