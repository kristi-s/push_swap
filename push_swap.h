//
// Created by Donny Roslyn on 6/13/21.
//

#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

typedef struct	s_stacks
{
	t_list*		stack_A;
	t_list*		stack_B;
	int			mid_1;
	int			mid_2;
	size_t 		count;
	int*		arr;
	int			min;
	int			max;
	int 		i;
}				t_stacks;

int				ft_error(void);
void			ft_creat_stack(char *str);
int				ft_check_arg(char *str);
int				ft_check_repeat(t_stacks* data);
void			ft_creat_stack_A(char *str,t_stacks* data);
int*			ft_new_int_content(int n);
t_stacks*		ft_init_struct();
void			ft_find_mid(char *str,t_stacks* data);
void			ft_init_array(t_stacks* data);
void			ft_sort_stack(t_stacks* data);
void			ft_divide_stack(t_stacks* data);
void			ft_merge_stack(t_stacks* data);
//void			ft_merge_stack_2(t_stacks* data);
void			ft_less_min(t_stacks* data);
void 			ft_more_max(t_stacks* data);
void 			ft_insert(t_stacks* data);

// ===== delete this!!!!
void ft_print_stack_A(t_stacks* data);
void ft_print_stack_B(t_stacks* data);
void proverka(t_stacks* data);
//

// operations
void		op_swap(t_list** lst, int flag_write);
void		op_swap_all(t_list** lst_A, t_list** lst_B);
void 		op_push(t_list** lst_A, t_list** lst_B, int flag_write);
void		op_rotate(t_list** lst, int flag_write);
void		op_rotate_all(t_list**	lst_A, t_list**	lst_B);
void		op_reverse_rotate(t_list** lst, int flag_write);
void		op_reverse_rotate_all(t_list**	lst_A, t_list**	lst_B);
void 		op_count_rotate(t_list** lst, int count, int flag_write);
void		op_count_reverse_rotate(t_list** lst, int count, int flag_write);

#endif //PUSH_SWAP_PUSH_SWAP_H
