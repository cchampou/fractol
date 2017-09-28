/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 14:41:48 by cchampou          #+#    #+#             */
/*   Updated: 2017/09/28 14:52:20 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_param *f)
{
	f->zoom = 0.005;
	f->depth = 50;
	f->ox = WIDTH / 2;
	f->oy = HEIGHT / 2;
}

void	render_julia(t_param *f)
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
			calc_julia_point(f, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	calc_julia_point(t_param *f, int x, int y)
{
	int		i;

	f->cr = 0.285;
	f->ci = 0.01;
	f->zr = (x - f->ox) * f->zoom;
	f->zi = (y - f->oy) * f->zoom;
	i = 0;
	while (f->zr * f->zr + f->zi * f->zi <= 4 && i < f->depth)
	{
		f->tmp = f->zr;
		f->zr = f->zr * f->zr - f->zi * f->zi + f->cr;
		f->zi = 2 * f->zi * f->tmp + f->ci;
		i++;
	}
	if (i < f->depth)
		put_pixel_to_img(f, x, y, rgb((char)0, (char)0, (char)(255 / f->depth) * i));
	else
		put_pixel_to_img(f, x, y, 0);
}
