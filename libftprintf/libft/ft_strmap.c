/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:49:14 by cchampou          #+#    #+#             */
/*   Updated: 2016/11/23 19:02:38 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f) (char))
{
	size_t	length;
	size_t	i;
	char	*out;

	i = 0;
	if (!s || !f)
		return (NULL);
	length = (size_t)ft_strlen((char*)s);
	if (!(out = (char*)malloc((length + 1) * sizeof(char))))
		return (NULL);
	while (s[i] != 0)
	{
		out[i] = f(s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
