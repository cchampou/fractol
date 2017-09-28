# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchampou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/27 10:22:49 by cchampou          #+#    #+#              #
#    Updated: 2017/09/28 15:02:58 by cchampou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

INC = includes minilibx_macos libftprintf/includes libftprintf/libft

LIB = libftprintf/libftprintf.a

MLX = minilibx_macos/libmlx.a

SRC_DIR = src/

OBJ_DIR = obj/

SRC = main.c error_checks.c error_throws.c mlx_init.c mlx_hooks.c mlx_tools.c \
	  mandelbrot.c julia.c ship.c

OBJ = $(SRC:.c=.o)

CC = clang

CFLAGS = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(LIB):
	make -C libftprintf

$(MLX):
	make -C minilibx_macos

$(OBJ_DIR):
	mkdir -p obj

$(NAME): $(OBJ_DIR) $(addprefix $(OBJ_DIR),$(OBJ)) $(LIB) $(MLX)
	$(CC) $(CFLAGS) $(addprefix $(OBJ_DIR),$(OBJ)) $(LIB) -o $@

$(OBJ_DIR)%.o: $(addprefix $(SRC_DIR), %.c)
	$(CC) $(addprefix -I, $(INC)) -c $< -o $@


clean:
	make -C libftprintf clean
	make -C minilibx_macos clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C libftprintf fclean
	make -C minilibx_macos clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re mlx
