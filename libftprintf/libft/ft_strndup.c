/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:50:18 by cchampou          #+#    #+#             */
/*   Updated: 2016/11/23 16:15:36 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*output;
	size_t	cpt;

	cpt = 0;
	if (!(output = (char*)malloc((n + 1) * sizeof(char))))
		return (NULL);
	while (cpt < n)
	{
		output[cpt] = s1[cpt];
		cpt++;
	}
	output[cpt] = '\0';
	return (output);
}
