/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 23:30:15 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/05 16:34:42 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(char **s, t_parse *e)
{
	size_t	i;

	i = 0;
	while (is_flag((*s)[i], e))
		i++;
	if (i > 0)
		*s = *s + i;
}

int		is_flag(char c, t_parse *e)
{
	if (c == '#')
		e->hashtag = 1;
	if (c == '+')
		e->plus = 1;
	if (c == '-')
		e->minus = 1;
	if (c == '0')
		e->zero = 1;
	if (c == ' ')
		e->space = 1;
	return (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0');
}
