/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:29:46 by cchampou          #+#    #+#             */
/*   Updated: 2016/11/24 19:22:57 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char *s, int separator)
{
	size_t	n;
	size_t	off;

	n = 0;
	off = 1;
	if (!s)
		return (0);
	while (*s)
	{
		n = (*s != separator && off) ? n + 1 : n;
		off = (*s == separator) ? 1 : 0;
		s++;
	}
	return (n);
}
