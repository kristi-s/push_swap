//
// Created by Donny Roslyn on 6/13/21.
//

//rra : reverse rotate a - shift down all elements of stack a by 1. The last element
//becomes the first one.

//rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
//becomes the first one.

//rrr : rra and rrb at the same time.

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
	if (flag_write == 1)
		write(1, "sa\n", 3);
	else if (flag_write == 2)
		write(1, "sb\n", 3);
	count_steps++;
}

void	op_swap_all(t_list**	lst_A, t_list**	lst_B)
{
	op_swap(lst_A, 0);
	op_swap(lst_B, 0);
	write(1, "rr\n", 3);
	count_steps++;
}

void 	op_push(t_list**	lst_A, t_list**	lst_B, int flag_write) // from A to B
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
	if (flag_write == 1)
		write(1, "pa\n", 3);
	else if (flag_write == 2)
		write(1, "pb\n", 3);
	count_steps++;
}

void	op_rotate(t_list**	lst, int flag_write)
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
	if (flag_write == 1)
		write(1, "ra\n", 3);
	else if (flag_write == 2)
		write(1, "rb\n", 3);
	count_steps++;

}

void	op_rotate_all(t_list**	lst_A, t_list**	lst_B)
{
	op_rotate(lst_A, 0);
	op_rotate(lst_B, 0);
	write(1, "rr\n", 3);
	count_steps++;
}

void	op_reverse_rotate(t_list**	lst, int flag_write)
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
	if (flag_write == 1)
		write(1, "rra\n", 4);
	else if (flag_write == 2)
		write(1, "rrb\n", 4);
	count_steps++;
}

void	op_reverse_rotate_all(t_list**	lst_A, t_list**	lst_B)
{
	op_reverse_rotate(lst_A, 0);
	op_reverse_rotate(lst_B, 0);
	write(1, "rrr\n", 4);
	count_steps++;
}

void 	op_count_rotate(t_list** lst, int count, int flag_write)
{
	while (count > 0)
	{
		op_rotate(lst, flag_write);
		count--;
	}
}

void 	op_count_reverse_rotate(t_list** lst, int count, int flag_write)
{
	while (count > 0)
	{
		op_reverse_rotate(lst, flag_write);
		count--;
	}
}

void 	op_count_rotate_all(t_stacks* data, int count)
{
	while (count > 0)
	{
		op_rotate_all(&data->stack_A, &data->stack_B);
		count--;
	}
}

void 	op_count_reverse_rotate_all(t_stacks* data, int count)
{
	while (count > 0)
	{
		op_reverse_rotate_all(&data->stack_A, &data->stack_B);
		count--;
	}
}



