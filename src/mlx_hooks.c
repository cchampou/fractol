/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 14:03:28 by cchampou          #+#    #+#             */
/*   Updated: 2017/09/28 15:50:38 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int key, t_param *f)
{
	if (key == 53)
		exit(1);
	if (key == 126)
		f->oy += 10;
	if (key == 125)
		f->oy -= 10;
	if (key == 123)
		f->ox += 10;
	if (key == 124)
		f->ox -= 10;
	render(f);
	return (0);
}

int		mouse_hook(int but, int x, int y, t_param *f)
{
	double	step;

	step = f->zoom / 4;
	if (but == 1)
	{
		f->ox -= step * (x - f->ox) / (f->zoom - step);
		f->oy -= step * (y - f->oy) / (f->zoom - step);
		f->zoom -= step;
	}
	if (but == 2)
	{
		f->ox += step * (x - f->ox) / (f->zoom + step);
		f->oy += step * (y - f->oy) / (f->zoom + step);
		f->zoom += step;
	}
	render(f);
	return (0);
}

int		mouse_motion(int x, int y, t_param *f)
{
	if (f->type == 2)
	{
		f->ci = (double)y / 1000;
		render(f);
	}
	return (0);
}
