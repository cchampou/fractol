/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:01:39 by cchampou          #+#    #+#             */
/*   Updated: 2017/09/13 18:10:57 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_prec(t_parse *e)
{
	char	*tmp;

	e->prec_value += ((ft_atoi(e->raw) < 0) ? 1 : 0);
	if (e->prec)
	{
		if (e->spec && (e->spec[0] == 's' || e->spec[0] == 'c'))
		{
			tmp = ft_strndup(e->raw, e->prec_value);
			free(e->raw);
			e->raw = tmp;
		}
		else if (prec_eligible(e->spec))
		{
			if (e->prec_value > ft_strlen(e->raw) - e->plus - e->space
					&& (e->spec[0] = 'o'
						|| e->spec[0] == 'O' || e->spec[0] == 'd'))
				push_left(e, '0', e->prec_value - ft_strlen(e->raw) + e->plus
						+ e->space);
			else
				reduce_value(e);
		}
		else if (e->prec_value > ft_strlen(e->raw))
			push_left(e, '0', e->prec_value - ft_strlen(e->raw) + e->plus);
	}
}

int		prec_eligible(char *spec)
{
	if (spec && (spec[0] == 'x' || spec[0] == 'X' || spec[0] == 'o'
				|| spec[0] == 'O' || spec[0] == 'd' || spec[0] == 'i'
				|| spec[0] == 'u'))
		return (1);
	return (0);
}

void	reduce_value(t_parse *e)
{
	int		i;
	char	*tmp;

	i = 0;
	if (e->spec[0] == 'x' && e->raw[2] == '0')
	{
		e->raw[2] = 0;
		e->length = 2;
	}
	if (e->hashtag && (e->spec[0] == 'o' || e->spec[0] == 'O'
				|| e->spec[0] == 'x'))
	{
	}
	else
	{
		while (e->raw[i] != 0 && ft_strlen(e->raw) - i > e->prec_value
			&& e->raw[i] == '0')
			i++;
		tmp = ft_strdup(e->raw + i);
		free(e->raw);
		e->raw = tmp;
	}
}
