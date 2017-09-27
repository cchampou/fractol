/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:28:28 by cchampou          #+#    #+#             */
/*   Updated: 2016/11/22 15:19:08 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*element;
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	if (!(element = (t_list*)malloc(sizeof(*element))))
		return (NULL);
	if (!content)
	{
		element->content = NULL;
		element->content_size = 0;
	}
	else
	{
		if (!(tmp = (unsigned char*)malloc(content_size * sizeof(*tmp))))
			return (NULL);
		element->content_size = content_size;
		while (i++ < content_size)
			tmp[i - 1] = ((unsigned char*)content)[i - 1];
		element->content = tmp;
	}
	element->next = NULL;
	return (element);
}
