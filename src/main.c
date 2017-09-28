/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 10:29:31 by cchampou          #+#    #+#             */
/*   Updated: 2017/09/28 15:04:32 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_param	*f;

	f = ft_memalloc(sizeof(t_param));
	args_check(ac, av, f);
	launch_mlx(f);
	init(f);
	render(f);
	mlx_loop(f->mlx);
	free(f);
	return (0);
}

void	init(t_param *f)
{
	if (f->type == 1)
		init_mandel(f);
	if (f->type == 2)
		init_julia(f);
	if (f->type == 3)
		init_ship(f);
}

void	render(t_param *f)
{
	if (f->type == 1)
		render_mandel(f);
	if (f->type == 2)
		render_julia(f);
	if (f->type == 3)
		render_ship(f);
}
