/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:30:06 by cchampou          #+#    #+#             */
/*   Updated: 2016/11/23 19:06:13 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	length;
	int	i;

	if (!s1 || !s2)
	{
		return (0);
	}
	i = 0;
	length = (int)ft_strlen(s1);
	if (length != (int)ft_strlen(s2))
		return (0);
	while (i < length)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
