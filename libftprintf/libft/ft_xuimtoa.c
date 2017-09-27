/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xuimtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 21:40:27 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/22 18:28:55 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_digits(uintmax_t nb)
{
	int	digits;

	digits = 0;
	while (nb && ++digits)
		nb /= 16;
	digits = (nb != 0) ? digits + 1 : digits;
	return (digits);
}

static char	convert_hexa(uintmax_t c)
{
	if (c <= 9)
		return (c + '0');
	if (c == 10)
		return ('a');
	if (c == 11)
		return ('b');
	if (c == 12)
		return ('c');
	if (c == 13)
		return ('d');
	if (c == 14)
		return ('e');
	if (c == 15)
		return ('f');
	return (0);
}

char		*ft_xuimtoa(uintmax_t n)
{
	int				digits;
	uintmax_t		buffer;
	char			*str;

	buffer = n;
	digits = (n <= 0) ? count_digits(buffer) + 1 : count_digits(buffer);
	if (!(str = malloc(sizeof(char) * (digits + 1))))
		return (NULL);
	str[digits--] = '\0';
	if (buffer == 0)
		str[0] = '0';
	while (buffer)
	{
		str[digits--] = convert_hexa(buffer % 16);
		buffer /= 16;
	}
	return (str);
}
