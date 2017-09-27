/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 08:20:38 by cchampou          #+#    #+#             */
/*   Updated: 2016/11/06 08:59:58 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char*)s;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			ptr = (char*)&s[i];
		}
		i++;
	}
	if (s[i] == '\0' && c == '\0')
	{
		ptr = (char*)&s[i];
		return (ptr);
	}
	return ((ptr == s && *ptr != c) ? NULL : ptr);
}
