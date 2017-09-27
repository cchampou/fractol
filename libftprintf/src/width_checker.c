/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 23:29:17 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/13 17:54:05 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width(char **s, t_parse *e)
{
	size_t	i;
	char	*value;

	value = NULL;
	i = 0;
	while (is_width_or_prec((*s)[i]))
		i++;
	if (i > 0)
	{
		e->width = 1;
		value = ft_strndup(*s, i);
		e->width_value = ft_atoi(value);
		*s = *s + i;
	}
	if (value)
		free(value);
}
