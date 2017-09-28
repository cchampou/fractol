/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:34:48 by cchampou          #+#    #+#             */
/*   Updated: 2017/09/28 15:40:58 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	launch_mlx(t_param *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, HEIGHT, WIDTH, "Fract'ol");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	mlx_hook(f->win, 6, 0, mouse_motion, f);
	mlx_key_hook(f->win, key_hook, f);
	mlx_mouse_hook(f->win, mouse_hook, f);
}
