//
// Created by Кристина Смирнова on 25.06.2021.
//

#include "push_swap.h"

void	ft_creat_stack_new(char *str)
{
	t_stacks* data;
	if (ft_check_arg(str))
	{
		ft_error();
		return ;
	}

	data = ft_init_struct();
	ft_creat_stack_A(str, data);
	ft_find_max_2(data);
	ft_find_mid(str, data);
	ft_divide_stack_2(data);
	while (data->stack_B)
		ft_sort_stack_2(data);
	ft_find_start_A(data);
//	ft_print_stack_A(data);
//	ft_print_stack_B(data);
}

void 	ft_find_max_2(t_stacks* data)
{
	t_list*	lst;
	int num_a;
	int pre_max;

	lst = data->stack_A;
	if (*(int*)lst->content < data->max)
		pre_max = *(int*)lst->content;
	else
		pre_max = *(int*)lst->next->content;
	while (lst)
	{
		num_a = *(int*)lst->content;
		if (num_a > pre_max && num_a < data->max)
			pre_max = num_a;
		lst = lst->next;
	}
	data->pre_max = pre_max;
//	printf("pre_max = %d\n", data->pre_max);
}

void 	ft_divide_stack_2(t_stacks* data)
{
	int num_a;
	size_t size;
	int first_el;

	num_a = *(int*)data->stack_A->content;
	if(num_a == data->max) {
		op_rotate(&data->stack_A, STACK_A);
		num_a = *(int*)data->stack_A->content;
	}
	size = ft_lstsize(data->stack_A);
	first_el = num_a;
	while (size > 2)
	{
		if (num_a < data->pre_max) {
			op_push(&data->stack_A, &data->stack_B, STACK_B);
			//dopolnenie
			if (num_a != first_el && num_a < data->mid_1)
//			if (num_a < first_el)
				op_rotate(&data->stack_B, STACK_B);
		}
		else
			op_rotate(&data->stack_A, STACK_A);
		num_a = *(int*)data->stack_A->content;
		size = ft_lstsize(data->stack_A);
	}
	if (num_a == data->max)
		op_rotate(&data->stack_A, STACK_A);

}

void 	ft_sort_stack_2(t_stacks* data)
{
	int i = 0;
	size_t size_b;
	int min = 1;

	int count;
	int save_i;

	size_b = ft_lstsize(data->stack_B);

	while (i < size_b / 2 && min > i)
	{
		count = ft_analise_op(data, i);
		if (count == 0)
		{
			op_push(&data->stack_B, &data->stack_A, STACK_A);
			return;
		}
		if (i == 0 || count < min) {
			min = count;
			save_i = i;
		}
		i++;
	}

	i = size_b - 1;
	while (i > size_b / 2 && min > size_b - i)
	{
		count = ft_analise_op(data, i);
		if (count < min)
		{
			min = count;
			save_i = i;
		}
		i--;
	}
	ft_do_push(data, save_i);
}

int 	ft_analise_op(t_stacks* data, int i)
{
	int 	rb;
	int 	ra;
	int 	rra = 0;
	int		rrb = 0;
	int 	rr = 0;
	int 	rrr = 0;
	int 	num_b;
	size_t 	size_a;
	size_t 	size_b;

	rb = i;
	size_b = ft_lstsize(data->stack_B);
	if (rb > size_b - rb)
	{
		rrb = size_b - rb;
		rb = 0;
	}
	num_b = ft_lst_take_content(&data->stack_B, i);
	ra = ft_find_count_ra(data, num_b);
	size_a = ft_lstsize(data->stack_A);
	if (ra > size_a - ra)
	{
		rra = size_a - ra;
		ra = 0;
	}
	if (ra > 0 && rb > 0)
	{
		if (ra > rb)
		{
			rr = rb;
			rb = 0;
			ra = ra - rr;
		}
		else
		{
			rr = ra;
			ra = 0;
			rb = rb - rr;
		}
	}
	if (rra > 0 && rrb > 0)
	{
		if (rra > rrb)
		{
			rrr = rrb;
			rrb = 0;
			rra = rra - rrr;
		}
		else
		{
			rrr = rra;
			rra = 0;
			rrb = rrb - rrr;
		}
	}
//	printf("rb: %d\t ra: %d\t rr: %d\t rra: %d\t rrb: %d\t rrr: %d\n", rb, ra, rr, rra, rrb, rrr);
	return (rb + ra + rr + rra + rrb + rrr);

}


int 	ft_lst_take_content(t_list** ptr_lst, int i)
{
	t_list* lst;

	lst = *ptr_lst;
	while (i > 0)
	{
		lst = lst->next;
		i--;
	}

	return *(int*)lst->content;
}

int 	ft_find_count_ra(t_stacks* data, int num_b)
{
	t_list* lst;
	t_list* pre_lst;
	int count_ra = 0;

	pre_lst = ft_lstlast(data->stack_A);
	lst = data->stack_A;
	while (lst)
	{
		if (num_b < *(int*)lst->content && (num_b > *(int*)pre_lst->content ||
				*(int*)pre_lst->content == data->max ))
			break;
		else
			count_ra++;

		pre_lst = lst;
		lst = lst->next;
	}
	return count_ra;
}

void 	ft_do_push(t_stacks* data, int i)
{
	int 	rb;
	int 	ra;
	int 	rra = 0;
	int		rrb = 0;
	int 	rr = 0;
	int 	rrr = 0;
	int 	num_b;
	size_t 	size_a;
	size_t 	size_b;

	rb = i;
	size_b = ft_lstsize(data->stack_B);
	if (rb > size_b - rb)
	{
		rrb = size_b - rb;
		rb = 0;
	}
	num_b = ft_lst_take_content(&data->stack_B, i);
	ra = ft_find_count_ra(data, num_b);
	size_a = ft_lstsize(data->stack_A);
	if (ra > size_a - ra)
	{
		rra = size_a - ra;
		ra = 0;
	}
	if (ra > 0 && rb > 0)
	{
		if (ra > rb)
		{
			rr = rb;
			rb = 0;
			ra = ra - rr;
		}
		else
		{
			rr = ra;
			ra = 0;
			rb = rb - rr;
		}
	}
	if (rra > 0 && rrb > 0)
	{
		if (rra > rrb)
		{
			rrr = rrb;
			rrb = 0;
			rra = rra - rrr;
		}
		else
		{
			rrr = rra;
			rra = 0;
			rrb = rrb - rrr;
		}
	}

	op_count_rotate_all(data, rr);
	op_count_reverse_rotate_all(data, rrr);
	op_count_rotate(&data->stack_A, ra, STACK_A);
	op_count_rotate(&data->stack_B, rb, STACK_B);
	op_count_reverse_rotate(&data->stack_A, rra, STACK_A);
	op_count_reverse_rotate(&data->stack_B, rrb, STACK_B);
	op_push(&data->stack_B, &data->stack_A, STACK_A);
}

void 	ft_find_start_A(t_stacks* data)
{
	size_t size_a;
	t_list*	lst;

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
}