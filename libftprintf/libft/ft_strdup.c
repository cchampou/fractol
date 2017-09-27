/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 01:23:12 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/12 15:14:22 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	char	*output;
	int		length;
	int		cpt;

	cpt = 0;
	length = ft_strlen(s1);
	if (!(output = (char*)malloc((length + 1) * sizeof(char))))
		return (NULL);
	while (cpt < length)
	{
		output[cpt] = s1[cpt];
		cpt++;
	}
	output[cpt] = '\0';
	return (output);
}
