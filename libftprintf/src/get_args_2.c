/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:52:11 by cchampou          #+#    #+#             */
/*   Updated: 2017/09/13 21:09:54 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_ouint(t_parse *e, va_list *ap)
{
	if (!ft_strcmp(e->spec, "O"))
		e->len = ft_strdup("l");
	if (e->len == NULL)
		e->raw = ft_ouimtoa((unsigned int)va_arg(*ap, uintmax_t));
	else if (!ft_strcmp(e->len, "hh"))
		e->raw = ft_ouimtoa((unsigned char)va_arg(*ap, int));
	else if (!ft_strcmp(e->len, "h"))
		e->raw = ft_ouimtoa((unsigned short int)va_arg(*ap, int));
	else if (!ft_strcmp(e->len, "l"))
		e->raw = ft_ouimtoa(((long int)va_arg(*ap, intmax_t)));
	else if (!ft_strcmp(e->len, "ll"))
		e->raw = ft_ouimtoa(((long long int)va_arg(*ap, intmax_t)));
	else if (!ft_strcmp(e->len, "j"))
		e->raw = ft_ouimtoa((va_arg(*ap, intmax_t)));
	else if (!ft_strcmp(e->len, "z"))
		e->raw = ft_ouimtoa((va_arg(*ap, size_t)));
}

void	get_xuint(t_parse *e, va_list *ap)
{
	if (e->len == NULL)
		e->raw = ft_xuimtoa((unsigned int)va_arg(*ap, intmax_t));
	else if (!ft_strcmp(e->len, "hh"))
		e->raw = ft_xuimtoa((unsigned char)va_arg(*ap, int));
	else if (!ft_strcmp(e->len, "h"))
		e->raw = ft_xuimtoa((unsigned short int)va_arg(*ap, int));
	else if (!ft_strcmp(e->len, "l"))
		e->raw = ft_xuimtoa(((unsigned long int)va_arg(*ap, uintmax_t)));
	else if (!ft_strcmp(e->len, "ll"))
		e->raw = ft_xuimtoa(((long long int)va_arg(*ap, uintmax_t)));
	else if (!ft_strcmp(e->len, "j"))
		e->raw = ft_xuimtoa((va_arg(*ap, intmax_t)));
	else if (!ft_strcmp(e->len, "z"))
		e->raw = ft_xuimtoa((va_arg(*ap, size_t)));
	if (e->spec[0] == 'X')
		e->raw = ft_strtoupper(e->raw);
	if (!ft_strcmp(e->raw, "0"))
		e->hashtag = 0;
}

void	get_pointer(t_parse *e, va_list *ap)
{
	free(e->spec);
	e->spec = ft_strdup("x");
	e->len = ft_strdup("ll");
	get_xuint(e, ap);
	e->hashtag = 1;
	if (!ft_strcmp(e->raw, "0"))
		e->hashtag = 1;
}

void	get_wchar(t_parse *e, va_list *ap)
{
	wchar_t	tmp;

	tmp = (wchar_t)va_arg(*ap, int);
	if (!(e->raw = ft_memalloc(4)))
		exit(-1);
	wchar_convert(e->raw, tmp);
	if (tmp == 0)
	{
		e->length = 1;
		if (!(e->raw = ft_memalloc(2)))
			exit(-1);
	}
}
