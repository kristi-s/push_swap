/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:35:07 by droslyn           #+#    #+#             */
/*   Updated: 2021/07/02 13:22:42 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*list;
	t_list	*tail_lst;

	if (!lst || !(*f))
		return (0);
	new_lst = ft_lstnew((*f)(lst->content));
	if (!new_lst)
		return (0);
	list = new_lst;
	tail_lst = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst = ft_lstnew((*f)(lst->content));
		if (!new_lst)
		{
			ft_lstclear(&list, del);
			return (0);
		}
		ft_lstadd_back(&tail_lst, new_lst);
		tail_lst = new_lst;
		lst = lst->next;
	}
	return (list);
}
