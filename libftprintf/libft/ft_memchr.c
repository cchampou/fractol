/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 07:15:07 by cchampou          #+#    #+#             */
/*   Updated: 2016/11/06 07:29:43 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	findme;

	i = 0;
	findme = (char)c;
	while (i < n)
	{
		if (((unsigned char*)s)[i] == findme)
		{
			s = &s[i];
			return ((void*)s);
		}
		i++;
	}
	return (NULL);
}
