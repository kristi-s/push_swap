//
// Created by Donny Roslyn on 6/13/21.
//
#include "push_swap.h"

void	ft_sort_stack(t_stacks* data)
{
	ft_divide_stack(data);
	ft_merge_stack(data);
	ft_less_min(data);
	ft_more_max(data);
//	ft_merge_stack_2(data);

//	while (!data->stack_B)
//	{
//		ft_less_min(data);
//		ft_more_max(data);
//	}

	printf("after ft_divide_stack and ft_merge_stack:\n");
	ft_print_stack_A(data);
	ft_print_stack_B(data);
}

void	ft_divide_stack(t_stacks* data)
{
	t_list* lst;
	int i = 0;

	lst = data->stack_A;
	while (i < data->count)
	{
		if (*(int*)lst->content > data->mid_1)
			op_push(&data->stack_A, &data->stack_B);
		else
			op_rotate(&data->stack_A);
		lst = data->stack_A;
		i++;
	}
	i = ft_lstsize(data->stack_A);
	while (i > 0)
	{
		if (*(int*)lst->content >= data->mid_2)
			op_push(&data->stack_A, &data->stack_B);
		else
			op_rotate(&data->stack_A);
		lst = data->stack_A;
		i--;
	}
	i = ft_lstsize(data->stack_A);
	while (i > 2)
	{
		op_push(&data->stack_A, &data->stack_B);
		lst = data->stack_A;
		i--;
	}
}

void	ft_merge_stack(t_stacks* data)
{
	int	num_a1;
	int num_a2;
	int	num_b1;
	int num_b2;
	t_list*		lst;

	num_a1 = *(int*)(data->stack_A->content);
	num_a2 = *(int*)(data->stack_A->next->content);
	num_b1 = *(int*)(data->stack_B->content);
	num_b2 = *(int*)(data->stack_B->next->content);
	if (num_a1 > num_a2)
	{
		if (num_b1 > num_b2)
			op_swap_all(&data->stack_A, &data->stack_B);
		else
		{
			if (num_b1 < num_a1 && num_b1 > num_a2)
			{
				while (num_b1 < num_a1 && num_b1 > num_a2)
				{
					op_push(&data->stack_B, &data->stack_A);
					num_a1 = num_b1;
					if (!data->stack_B)
						break;
					num_b1 = *(int *) (data->stack_B->content);
				}
				op_reverse_rotate(&data->stack_A);
			}
			else
				op_swap(&data->stack_A);
		}
		data->min = num_a2;

	}
	else
		data->min = num_a1;
	lst = ft_lstlast(data->stack_A);
	data->max = *(int*)lst->content;
}

void	ft_less_min(t_stacks* data)
{
	int num_b1;

	while (data->stack_B)
	{
		num_b1 = *(int *) (data->stack_B->content);
		if (num_b1 < data->min) {
			op_push(&data->stack_B, &data->stack_A);
			data->min = num_b1;
		}
		else
			return ;
	}
}

void 	ft_more_max(t_stacks* data)
{
	int num_b1;

	while (data->stack_B)
	{
		num_b1 = *(int *) (data->stack_B->content);
		if (num_b1 > data->max) {
			op_push(&data->stack_B, &data->stack_A);
			if (data->stack_B->next && (*(int *)(data->stack_B->next->content) < num_b1) &&
					(*(int *)(data->stack_B->next->content) > data->max))
			{
				op_push(&data->stack_B, &data->stack_A);
				op_reverse_rotate(&data->stack_A);
			}
			op_reverse_rotate(&data->stack_A);
			data->max = num_b1;
		}
		else
			return ;
	}
}