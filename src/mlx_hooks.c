/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 14:03:28 by cchampou          #+#    #+#             */
/*   Updated: 2017/09/27 18:28:17 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int key, t_param *f)
{
	if (key == 53)
		exit(1);
	if (key == 78)
		f->zoom *= 1.1;
	if (key == 69)
		f->zoom /= 1.1;
	if (key == 126)
		f->oy += 10;
	if (key == 125)
		f->oy -= 10;
	if (key == 123)
		f->ox += 10;
	if (key == 124)
		f->ox -= 10;
	render_mandel(f);
	return (0);
}

int		mouse_hook(int but, int x, int y, t_param *f)
{
	double	step;

	step = 0.0005;
	if (but == 1)
	{
		ft_putnbr(f->ox);
		f->ox += step * (x - f->ox) / (f->zoom + step);
		f->oy += step * (y - f->oy) / (f->zoom + step);
		f->zoom += step;
		ft_putnbr(f->ox);
	}
	if (but == 2)
	{
		f->zoom += step;
	}
	render_mandel(f);
	return (0);
}
