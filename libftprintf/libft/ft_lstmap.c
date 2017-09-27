/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:24:15 by cchampou          #+#    #+#             */
/*   Updated: 2016/11/23 19:20:06 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*newlst;
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	new = ft_lstnew(tmp->content, tmp->content_size);
	newlst = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if ((new->next = ft_lstnew(tmp->content, tmp->content_size)))
			new = new->next;
		else
			return (NULL);
		lst = lst->next;
	}
	return (newlst);
}
