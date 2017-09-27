/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <cchampou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 15:32:33 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/22 18:17:38 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_parse	*create(void)
{
	t_parse	*e;

	if (!(e = (t_parse*)malloc(sizeof(t_parse))))
		exit(0);
	e->next = NULL;
	e->raw = NULL;
	e->hashtag = 0;
	e->plus = 0;
	e->minus = 0;
	e->zero = 0;
	e->space = 0;
	e->width = 0;
	e->width_value = 0;
	e->prec = 0;
	e->prec_value = 0;
	e->len = NULL;
	e->spec = NULL;
	e->length = 0;
	return (e);
}

void	push_back(t_parse **list, t_parse *e)
{
	t_parse	*tmp;

	if (*list == NULL)
		*list = e;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = e;
	}
}

int		print(t_parse **list)
{
	t_parse	*tmp;
	int		out;

	out = 0;
	tmp = *list;
	while (tmp)
	{
		if (tmp->length)
		{
			out += tmp->length;
			ft_putnstr(tmp->raw, tmp->length);
		}
		else
		{
			out += ft_strlen(tmp->raw);
			ft_putstr(tmp->raw);
		}
		tmp = tmp->next;
	}
	return (out);
}

void	freelist(t_parse **list)
{
	t_parse	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->raw)
			free((*list)->raw);
		if ((*list)->len)
			free((*list)->len);
		if ((*list)->spec)
			free((*list)->spec);
		free(*list);
		*list = tmp;
	}
}
