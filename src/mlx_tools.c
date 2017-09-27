/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 14:16:46 by cchampou          #+#    #+#             */
/*   Updated: 2017/09/27 15:31:27 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_img(t_param *f, int x, int y, int color)
{
	char	*tmp;

	tmp = mlx_get_data_addr(f->img, &f->bpp, &f->size_line, &f->endian);
	tmp += y * f->size_line;
	tmp += x * f->bpp / 8;
	tmp[0] = color;
	tmp[1] = color >> 8;
	tmp[2] = color >> 16;
}

int		rgb(char red, char green, char blue)
{
	return ((red & 0x00FF0000) | (green & 0x0000FF00) | (blue & 0x000000FF));
}
