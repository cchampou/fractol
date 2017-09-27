/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:54:28 by cchampou          #+#    #+#             */
/*   Updated: 2016/11/23 20:21:12 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strsplit(char const *s, char c)
{
	char	**table;
	int		words;
	int		cpt;
	int		length;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	cpt = ft_strlen(s);
	if (!s || !(table = (char**)malloc(sizeof(table) * (words + 1))))
		return (NULL);
	table[words] = NULL;
	while (cpt-- >= 0)
	{
		if (s[cpt] != c)
		{
			length = cpt;
			while (s[cpt] != c && cpt != -1)
				--cpt;
			table[--words] = ft_strsub(s, cpt + 1, length - cpt);
		}
	}
	return (table);
}
