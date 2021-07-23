/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:20:00 by droslyn           #+#    #+#             */
/*   Updated: 2021/07/02 20:08:18 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define STACK_A 1
# define STACK_B 2
# define WRITE 1
# define NO_WRITE 0
# define OK 1
# define KO 0
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_stacks
{
	t_list	*stack_A;
	t_list	*stack_B;
	int		mid;
	int		count;
	int		*arr;
	int		min;
	int		max;
	int		pre_max;
	size_t	i;
	size_t	save_i;
	size_t	min_count;
}			t_stacks;

typedef struct s_cmd
{
	size_t	ra;
	size_t	rb;
	size_t	rra;
	size_t	rrb;
	size_t	rr;
	size_t	rrr;
	int		num_b;
	size_t	size_a;
	size_t	size_b;
}			t_cmd;

int			ft_error(void);
void		ft_error_and_exit(void);
void		ft_free(t_stacks *data);
void		ft_creat_stack(char *str);
int			ft_check_arg(char *str, int i, int count_num, char *ptr);
int			ft_check_repeat(t_stacks *data);
void		ft_creat_stack_A(char *str, t_stacks *data, int i);
int			*ft_new_int_content(int n);
t_stacks	*ft_init_struct(void);
void		ft_find_mid(t_stacks *data);
void		ft_main_body(int argc, char **argv);
size_t		ft_analise_op(t_stacks *data, int i);
t_cmd		*ft_init_info_cmd(t_stacks *data);
int			ft_analise_op_rev(t_stacks *data, int i);
void		ft_do_push(t_stacks *data, int i);
void		ft_find_start_A(t_stacks *data);
int			ft_check_sort(t_list **lst_stack);
void		ft_sort_three(t_stacks *data);
void		ft_rb_or_rrb(t_cmd *info_cmd);
void		ft_ra_or_rra(t_cmd *info_cmd);
void		ft_count_rr(t_cmd *info_cmd);
void		ft_count_rrr(t_cmd *info_cmd);
size_t		ft_sum_cmd(t_cmd *info_cmd);
void		op_swap(t_list **lst, int flag_write);
void		op_swap_all(t_list **lst_A, t_list **lst_B, int flag_write);
void		op_push(t_list **lst_A, t_list **lst_B, int flag_write);
void		op_rotate(t_list **lst, int flag_write);
void		op_rotate_all(t_list **lst_A, t_list **lst_B, int flag_write);
void		op_reverse_rotate(t_list **lst, int flag_write);
void		op_reverse_rotate_all(t_list **lst_A, t_list **lst_B, \
								int flag_write);
void		op_count_rotate(t_list **lst, int count, int flag_write);
void		op_count_reverse_rotate(t_list **lst, int count, int flag_write);
void		op_count_rotate_all(t_stacks *data, int count);
void		op_count_reverse_rotate_all(t_stacks *data, int count);
void		op_count_push(t_stacks *data, int count, int flag_write);
int			ft_read_line(int fd, char **line);
void		ft_creat_stack_checker(int argc, char **argv);
void		ft_parse_cmd(char *line, t_stacks *data);
void		ft_ra(t_stacks *data);
void		ft_rb(t_stacks *data);
void		ft_rr(t_stacks *data);
void		ft_rra(t_stacks *data);
void		ft_rrb(t_stacks *data);
void		ft_rrr(t_stacks *data);
void		ft_pa(t_stacks *data);
void		ft_pb(t_stacks *data);
void		ft_sa(t_stacks *data);
void		ft_sb(t_stacks *data);
void		ft_ss(t_stacks *data);
void		ft_return(int res);

#endif
