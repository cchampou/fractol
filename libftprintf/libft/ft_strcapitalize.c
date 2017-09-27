/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:48:22 by cchampou          #+#    #+#             */
/*   Updated: 2016/11/23 18:31:10 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *s)
{
	char	*ptr;

	ptr = s;
	if (ft_islower(*s))
		*s = ft_toupper(*s);
	s++;
	while (*s)
	{
		if (!(ft_isblank(*(s - 1)) && ft_isupper(*s)))
			*s = ft_tolower(*s);
		if (!(ft_isalnum(*(s - 1))) && ft_islower(*s))
			*s = ft_toupper(*s);
		s++;
	}
	return (ptr);
}
