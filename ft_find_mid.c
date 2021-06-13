//
// Created by Donny Roslyn on 6/13/21.
//

#include "push_swap.h"
#include <stdlib.h>

int		compare(const void* n1, const void* n2)
{
	return *(int*)n1 - *(int*)n2;
}

void			ft_find_mid(char *str,t_stacks* data)
{
	int			half_count;

	ft_init_array(data);

	qsort(data->arr, data->count, sizeof(int), &compare);	// !!!!!  TODO заменить сортировку
	// ----delete !!!
//	for(int i = 0; i < data->count; i++)
//	{
//		printf("arr: %d\n", data->arr[i]);
//	}

	if (data->count % 2 == 0)
		half_count = data->count / 2 - 1;
	else
		half_count = data->count / 2;

	printf("half_count = %d\n", half_count); // TODO delete this

	data->mid_1 = data->arr[half_count];

	if (data->count % 2 == 0)
		half_count++;
	printf("half_count = %d\n", half_count);
	if (half_count % 2 == 0)
		half_count = half_count / 2 - 1;
	else
		half_count = half_count / 2;

	data->mid_2 = data->arr[half_count];
}


void			ft_init_array(t_stacks* data)
{
	int* 		new_arr;
	t_list*		lst;

	new_arr = ft_calloc(data->count, sizeof(int));
	if (!new_arr)
	{
		ft_error();
		exit(1);
	}
	data->arr = new_arr;
	lst = data->stack_A;
	while (lst)
	{
		*new_arr = *(int*)lst->content;
		lst = lst->next;
		new_arr++;
	}
}
