# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchampou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/27 10:22:49 by cchampou          #+#    #+#              #
#    Updated: 2017/09/27 12:29:53 by cchampou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

INC = includes minilibx_macos libftprintf/includes libftprintf/libft

LIB = libftprintf/libftprintf.a

SRC_DIR = src/

OBJ_DIR = obj/

SRC = main.c error_checks.c error_throws.c

OBJ = $(SRC:.c=.o)

CC = clang

CFLAGS = $(addprefix -I, $(INC))

all: $(NAME)

$(LIB):
	make -C libftprintf

$(OBJ_DIR):
	mkdir -p obj

$(NAME): $(OBJ_DIR) $(addprefix $(OBJ_DIR),$(OBJ)) $(LIB)
	$(CC) $(CFLAGS) $(addprefix $(OBJ_DIR),$(OBJ)) $(LIB) -o $@

$(OBJ_DIR)%.o: $(addprefix $(SRC_DIR), %.c)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libftprintf clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C libftprintf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
