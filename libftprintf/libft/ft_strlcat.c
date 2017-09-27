/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 22:39:54 by cchampou          #+#    #+#             */
/*   Updated: 2016/11/26 11:40:34 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	enddst;
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	enddst = 0;
	i = 0;
	while (dst[enddst] && enddst < size)
		enddst++;
	while (src[i] && enddst + i < size - 1)
	{
		dst[enddst + i] = src[i];
		i++;
	}
	if (enddst + i < size)
		dst[enddst + i] = '\0';
	return (enddst + ft_strlen(src));
}
