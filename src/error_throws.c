/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_throws.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:31:21 by cchampou          #+#    #+#             */
/*   Updated: 2017/09/27 12:34:07 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	throw_few(void)
{
	write(2, "fractol: too few arguments\n", 27);
	throw_usage();
	exit(-1);
}

void	throw_many(void)
{
	write(2, "fractol: too many arguments\n", 28);
	throw_usage();
	exit(-1);
}

void	throw_invalid(void)
{
	write(2, "fractol: invalid type\n", 22);
	throw_usage();
	exit(-1);
}

void	throw_usage(void)
{
	write(2, "usage: ./fractol [type]\n", 24);
}
