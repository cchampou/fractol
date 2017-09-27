# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchampou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/10 09:14:12 by cchampou          #+#    #+#              #
#    Updated: 2017/06/14 11:02:16 by cchampou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = clang

CFLAGS = -Iincludes -Ilibft

LIBFT = libft/libft.a

CDIR = src

CFILES	=	ft_printf.c				\
			parse_param.c			\
			parse_list_manager.c	\
			spec_checker.c			\
			flags_checker.c			\
			len_checker.c			\
			percent_checker.c		\
			prec_checker.c			\
			width_checker.c			\
			treat.c			\
			args.c			\
			get_args_1.c			\
			get_args_2.c			\
			apply_flags.c			\
			strutils.c			\
			apply_width.c		\
			apply_prec.c			\
			wchar.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(CFLAGS) -c $(patsubst %,$(CDIR)/%,$(CFILES))
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OFILES)

%.o:%.c

clean:
	@make -C libft clean
	@rm -f $(OFILES)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

.PHONY: clean

re: fclean all
