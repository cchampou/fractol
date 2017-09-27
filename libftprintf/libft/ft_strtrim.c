/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:23:14 by cchampou          #+#    #+#             */
/*   Updated: 2016/11/23 19:09:08 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		end;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	end = (int)ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while ((end > i) && (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		end--;
	if (!(str = (char*)malloc(sizeof(char) * (end - i + 2))))
		return (NULL);
	while (j < end - i + 1)
	{
		str[j] = s[i + j];
		j++;
	}
	str[j] = 0;
	return (str);
}
