/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:11:19 by cchampou          #+#    #+#             */
/*   Updated: 2016/11/23 19:03:19 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	size_t	i;
	size_t	length;
	char	*out;

	if (!s || !f)
		return (NULL);
	i = 0;
	length = (size_t)ft_strlen((char*)s);
	out = ft_strnew(length);
	if (out && s)
	{
		while (s[i] != 0)
		{
			out[i] = f((unsigned int)i, s[i]);
			i++;
		}
		return (out);
	}
	return (NULL);
}
