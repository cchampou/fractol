/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 04:33:42 by cchampou          #+#    #+#             */
/*   Updated: 2016/11/26 11:39:31 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	int				j;

	i = 0;
	j = (int)len;
	if (dst < src)
	{
		while (i < j)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i++;
		}
	}
	else
	{
		while (i++ < j)
			((unsigned char*)dst)[j - i] = ((unsigned char*)src)[j - i];
	}
	return (dst);
}
