/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 10:30:36 by cchampou          #+#    #+#             */
/*   Updated: 2017/09/27 12:25:53 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "ft_printf.h"
# include <unistd.h>

typedef struct	s_param
{
	int			type;
}				t_param;


void	args_check(int ac, char **av, t_param *f);
void	check_type(char **av, t_param *f);

void	throw_invalid(void);
void	throw_many(void);
void	throw_few(void);
void	throw_usage(void);

#endif
