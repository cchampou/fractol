/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:19:24 by cchampou          #+#    #+#             */
/*   Updated: 2016/11/22 15:42:23 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del) (void *, size_t))
{
	if (*alst)
	{
		del((*alst)->content, (*alst)->content_size * sizeof(unsigned char));
		free((void*)(*alst));
		*alst = NULL;
	}
}
