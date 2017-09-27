/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 10:29:31 by cchampou          #+#    #+#             */
/*   Updated: 2017/09/27 16:54:54 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_param	*f;

	f = ft_memalloc(sizeof(t_param));
	args_check(ac, av, f);
	launch_mlx(f);
	init_mandel(f);
	render_mandel(f);


	mlx_loop(f->mlx);
	free(f);
	return (0);
}
