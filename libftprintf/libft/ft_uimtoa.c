/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 20:03:15 by cchampou          #+#    #+#             */
/*   Updated: 2017/06/08 20:07:02 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_digits(uintmax_t nb)
{
	int	digits;

	digits = 0;
	while (nb && ++digits)
		nb /= 10;
	digits = (nb != 0) ? digits + 1 : digits;
	return (digits);
}

char		*ft_uimtoa(uintmax_t n)
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
		str[digits--] = '0' + buffer % 10;
		buffer /= 10;
	}
	return (str);
}
