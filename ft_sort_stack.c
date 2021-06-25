//
// Created by Donny Roslyn on 6/13/21.
//
#include "push_swap.h"

void	ft_sort_stack(t_stacks* data)
{
	size_t size_a;
	t_list*	lst;

	ft_divide_stack(data);
	ft_merge_stack(data);
//	ft_less_min(data);
//	ft_more_max(data);
//	ft_insert(data);
//	ft_merge_stack_2(data);

	while (data->stack_B)
	{
		ft_less_min(data);
		ft_more_max(data);
		ft_insert(data);
		//ft_print_stack_A(data); // TODO delete this!!!!
	}

	if (*(int*)(data->stack_A->content) != data->min)
	{
		data->i = 0;
		lst = data->stack_A;
		size_a = ft_lstsize(data->stack_A);
		while (lst && *(int*)(lst->content) != data->min)
		{
			lst = lst->next;
			data->i++;
		}

		if (data->i <= size_a - data->i)
			op_count_rotate(&data->stack_A, data->i, 1);
		else
			op_count_reverse_rotate(&data->stack_A, size_a -  data->i, 1);
	}

//	printf("after ft_divide_stack and ft_merge_stack:\n");
//	ft_print_stack_A(data);
//	ft_print_stack_B(data);
}

void	ft_divide_stack(t_stacks* data)
{
	t_list* lst;
	int i = 0;

	lst = data->stack_A;
	while (i < data->count)
	{
		if (*(int*)lst->content < data->mid_1)
			op_push(&data->stack_A, &data->stack_B, 2);
		else
			op_rotate(&data->stack_A, 1);
		lst = data->stack_A;
		i++;
	}
	i = ft_lstsize(data->stack_A);
	while (i > 2)
	{
		if (*(int*)lst->content <= data->mid_2)
			op_push(&data->stack_A, &data->stack_B, 2);
		else
			op_rotate(&data->stack_A, 1);
		lst = data->stack_A;
		i--;
	}
	i = ft_lstsize(data->stack_A);
	while (i > 2)
	{
		op_push(&data->stack_A, &data->stack_B, 2);
//		lst = data->stack_A;
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
					op_push(&data->stack_B, &data->stack_A, 1);
					num_a1 = num_b1;
					if (!data->stack_B)
						break;
					num_b1 = *(int *) (data->stack_B->content);
				}
				op_reverse_rotate(&data->stack_A, 1);
			}
			else
				op_swap(&data->stack_A, 1);
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
	size_t size_a;
	t_list* lst;

	while (data->stack_B)
	{
		num_b1 = *(int *) (data->stack_B->content);
		if (num_b1 < data->min) {
			lst = data->stack_A;
			data->i = 0;
			while (*(int*)lst->content != data->min)
			{
				data->i++;
				lst = lst->next;
			}
			if (data->i != 0)
			{
				size_a = ft_lstsize(data->stack_A);
				if (data->i < size_a - data->i)
					op_count_rotate(&data->stack_A, data->i, 1);
				else
					op_count_reverse_rotate(&data->stack_A, size_a -  data->i, 1);
			}
			op_push(&data->stack_B, &data->stack_A, 1);
			data->min = num_b1;
		}
		else
			return ;
	}
}

void 	ft_more_max(t_stacks* data)
{
	int num_b1;
	size_t size_a;
	t_list* lst;

	while (data->stack_B)
	{
		num_b1 = *(int *) (data->stack_B->content);
		if (num_b1 > data->max) {
			// найти расположение мах
			lst = data->stack_A;
			data->i = 0;
			while (*(int*)lst->content != data->max)
			{
				data->i++;
				lst = lst->next;
			}
			if (data->i != 0)
			{
				size_a = ft_lstsize(data->stack_A);
				if (data->i < size_a - data->i) {
					op_count_rotate(&data->stack_A, data->i, 1);
					op_push(&data->stack_B, &data->stack_A, 1);
					op_swap(&data->stack_A, 1);
				}
				else {
					op_count_reverse_rotate(&data->stack_A, size_a -  data->i, 1);
					op_push(&data->stack_B, &data->stack_A, 1);
				}

			}

			if (data->stack_B->next && (*(int *)(data->stack_B->next->content) < num_b1) &&
					(*(int *)(data->stack_B->next->content) > data->max))
			{

				op_push(&data->stack_B, &data->stack_A, 1);
				op_rotate(&data->stack_A, 1);
			}
//			op_rotate(&data->stack_A, 1);
			data->max = num_b1;
		}
		else
			return ;
	}
}

void 	ft_insert(t_stacks* data) {
	int num_b1;
	int num_b2;
	t_list *lst;
	t_list *lst_last;
	size_t size_a;

	int num_a1;
	int num_a2;

	data->i = 0;
	if (!data->stack_B)
		return;
	lst = data->stack_A;
	size_a = ft_lstsize(data->stack_A);
	num_b1 = *(int *) (data->stack_B->content);
	lst_last = ft_lstlast(data->stack_A);
	num_a1 = *(int *) lst->content;
	if (num_b1 < num_a1 && num_b1 > *(int *) lst_last->content)
	{
		op_push(&data->stack_B, &data->stack_A, 1);
		return;
	}
	while (lst) {
		num_a1 = *(int *) lst->content;
		if (lst->next && num_b1 < *(int*)lst->next->content &&
				num_b1 > num_a1)
		{
			num_a2 = *(int*)lst->next->content;
			data->i++;
			if (data->i < size_a - data->i)
				op_count_rotate(&data->stack_A, data->i, 1);
			else
				op_count_reverse_rotate(&data->stack_A, size_a - data->i, 1);
			op_push(&data->stack_B, &data->stack_A, 1);

			if (data->stack_B)
			{
				num_b2 = *(int *) (data->stack_B->content);
				if (num_b2 > num_a1 && num_b2 < num_a2)
				{
					op_push(&data->stack_B, &data->stack_A, 1);
					if (num_b2 > num_b1)
						op_swap(&data->stack_A, 1);

				}
			}
//			size_a = ft_lstsize(data->stack_A);
//			if (i <= size_a - i)
//				op_count_reverse_rotate(&data->stack_A, i, 1);
//			else
//				op_count_rotate(&data->stack_A, size_a -  i, 1);
			return ;
		}
		else
		{
			data->i++;
			lst = lst->next;
		}
	}

}