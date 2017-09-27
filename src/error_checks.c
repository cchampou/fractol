/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 10:45:05 by cchampou          #+#    #+#             */
/*   Updated: 2017/09/27 12:28:22 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	args_check(int ac, char **av, t_param *f)
{
	if (ac > 2)
		throw_many();
	if (ac < 2)
		throw_few();
	check_type(av, f);
}

void	check_type(char **av, t_param *f)
{
	if (!ft_strcmp(av[1], "mandelbrot"))
		f->type = 1;
	else if (!ft_strcmp(av[1], "julia"))
		f->type = 2;
	else if (!ft_strcmp(av[1], "ship"))
		f->type = 3;
	else
		throw_invalid();
}
