//
// Created by Donny Roslyn on 6/13/21.
//

#include "push_swap.h"
void ft_print_stack_A(t_stacks* data)
{
	t_list*	lst;

	lst = data->stack_A;
	if (!lst)
		printf("stack A is empty\n");
	while (lst)
	{
		printf("A: %d\n", *(int*)lst->content);
		lst = lst->next;
	}
}

void ft_print_stack_B(t_stacks* data)
{
	t_list*	lst;

	lst = data->stack_B;
	if (!lst)
		printf("stack B is empty\n");
	while (lst)
	{
		printf("B: %d\n", *(int*)lst->content);
		lst = lst->next;
	}
}

void proverka(t_stacks* data)
{
	ft_print_stack_A(data);
	op_swap(&data->stack_A);
	printf("after swap A:\n");
	ft_print_stack_A(data);
	op_push(&data->stack_A, &data->stack_B);
	op_push(&data->stack_A, &data->stack_B);
	op_push(&data->stack_A, &data->stack_B);
	printf("after push from A to B:\n");
	ft_print_stack_A(data);
	ft_print_stack_B(data);
	//	op_push(&data->stack_B, &data->stack_A);
	//	printf("after push from B to A:\n");
	//	ft_print_stack_A(data);
	//	ft_print_stack_B(data);
	op_reverse_rotate_all(&data->stack_A, &data->stack_B);
	printf("after rev_rotate A:\n");
	ft_print_stack_A(data);
	ft_print_stack_B(data);
}