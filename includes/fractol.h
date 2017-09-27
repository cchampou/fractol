/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 10:30:36 by cchampou          #+#    #+#             */
/*   Updated: 2017/09/27 17:06:34 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "ft_printf.h"
# include <unistd.h>

# define HEIGHT	800
# define WIDTH	800


typedef struct	s_param
{
	int			type;
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	int			size_line;
	int			endian;
	double		zoom;
	int			depth;
	double		ox;
	double		oy;
	double		cr;
	double		ci;
	double		zr;
	double		zi;
	double		tmp;
}				t_param;

void	init_mandel(t_param *f);
void	render_mandel(t_param *f);
void	calc_mandel_point(t_param *f, int x, int y);

void	put_pixel_to_img(t_param *f, int x, int y, int color);
int		rgb(char red, char green, char blue);

int		key_hook(int key, t_param *f);
int		mouse_hook(int but, int x, int y, t_param *f);

void	launch_mlx(t_param *f);

void	args_check(int ac, char **av, t_param *f);
void	check_type(char **av, t_param *f);

void	throw_invalid(void);
void	throw_many(void);
void	throw_few(void);
void	throw_usage(void);

#endif
