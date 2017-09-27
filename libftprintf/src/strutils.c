/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:58:40 by cchampou          #+#    #+#             */
/*   Updated: 2017/09/08 14:51:04 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	push_left(t_parse *e, char c, size_t nb)
{
	char	*sout;
	size_t	i;

	i = 0;
	refresh_length(e, nb);
	if (!(sout = ft_memalloc(e->length + 2)))
		exit(-1);
	if ((e->raw[i] == '-' || e->raw[i] == '+' || e->raw[i] == ' ') && c == '0')
	{
		sout[i] = e->raw[i];
		i++;
		nb++;
	}
	if (c != ' ' && e->raw[i] == '0'
			&& (e->raw[i + 1] == 'x' || e->raw[i + 1] == 'X'))
	{
		ft_strncpy(sout, e->raw, 2);
		i += 2;
		nb += 2;
	}
	ft_strncpy(sout + nb, e->raw + i, e->length);
	while (i < nb)
		sout[i++] = c;
	free(e->raw);
	e->raw = sout;
}

void	refresh_length(t_parse *e, size_t nb)
{
	if (e->length == 0)
		e->length = ft_strlen(e->raw);
	e->length += nb;
}

void	push_right(t_parse *e, char c, size_t nb)
{
	char	*sout;
	size_t	i;

	i = 0;
	if (e->length == 0)
		e->length = ft_strlen(e->raw);
	e->length += nb;
	if (!(sout = (char*)malloc(sizeof(char) * (e->length + 1))))
		exit(-1);
	if (c != ' ' && (e->raw[i] == '-' || e->raw[i] == '+'))
	{
		sout[i] = e->raw[i];
		i++;
		nb++;
	}
	while (i < nb)
	{
		sout[e->length - nb + i] = c;
		i++;
	}
	ft_strncpy(sout, e->raw, e->length - nb);
	free(e->raw);
	e->raw = ft_strdup(sout);
	free(sout);
}
