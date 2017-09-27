/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:27:34 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/22 16:49:29 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_flags(t_parse *e)
{
	if (e->space && e->spec && e->spec[0] != 's' && e->spec[0] != 'C'
			&& e->spec[0] != 'S' && e->spec[0] != 'x' && e->spec[0] != 'o'
			&& e->spec[0] != 'X')
		apply_space(e);
	if (e->plus && ft_strcmp(e->spec, "C") && ft_strcmp(e->spec, "s"))
		apply_plus(e);
	if (e->hashtag)
		apply_hashtag(e);
}

void	apply_space(t_parse *e)
{
	if (!ft_strchr(e->raw, '-') && e->spec != NULL && e->spec[0] != 'u'
			&& e->spec[0] != 'c')
	{
		push_left(e, ' ', 1);
	}
}

void	apply_plus(t_parse *e)
{
	if (!ft_strchr(e->raw, '-') && e->spec[0] != 'x' && e->spec[0] != 'X'
			&& e->spec[0] != 'o' && e->spec[0] != 'O' && e->spec[0] != 'u'
			&& e->spec[0] != 'c')
	{
		if (e->raw[0] == ' ')
			e->raw[0] = '+';
		else
			push_left(e, '+', 1);
	}
}

void	apply_hashtag(t_parse *e)
{
	if (ft_strcmp(e->raw, "") && e->spec[0] == 'x')
		push_left(e, 'x', 1);
	if (ft_strcmp(e->raw, "") && e->spec[0] == 'X')
		push_left(e, 'X', 1);
	if (ft_strcmp(e->raw, "0") && ft_strcmp(e->raw, "") && (e->spec[0] == 'o'
				|| e->spec[0] == 'O'
				|| e->spec[0] == 'x' || e->spec[0] == 'X'))
		push_left(e, '0', 1);
}
