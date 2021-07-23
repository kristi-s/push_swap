/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:04:51 by droslyn           #+#    #+#             */
/*   Updated: 2021/07/02 13:20:33 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*ptr_next;

	if (!lst || !(*del))
		return ;
	ptr = *lst;
	while (ptr)
	{
		ptr_next = ptr->next;
		(*del)(ptr->content);
		free(ptr);
		ptr = ptr_next;
	}
	*lst = 0;
}
