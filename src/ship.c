/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 15:03:07 by cchampou          #+#    #+#             */
/*   Updated: 2017/09/28 16:00:23 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_ship(t_param *f)
{
	f->zoom = 0.005;
	f->depth = 50;
	f->ox = WIDTH / 2;
	f->oy = HEIGHT / 2;
}

void	render_ship(t_param *f)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			calc_ship_point(f, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	calc_ship_point(t_param *f, int x, int y)
{
	int		i;

	f->cr = (x - f->ox) * f->zoom;
	f->ci = (y - f->oy) * f->zoom;
	f->zr = 0;
	f->zi = 0;
	i = 0;
	while (f->zr * f->zr + f->zi * f->zi < 4 && i < f->depth)
	{
		f->tmp = f->zr;
		f->zr = f->zr * f->zr - f->zi * f->zi + f->cr;
		f->zi = 2 * val_abs(f->zi * f->tmp) + f->ci;
		i++;
	}
	if (i < f->depth)
		ppti(f, x, y, rgb((char)0, (char)0, (char)(255 / f->depth) * i));
	else
		ppti(f, x, y, 0);
}

double	val_abs(double nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}
