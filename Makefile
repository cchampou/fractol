# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchampou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/27 10:22:49 by cchampou          #+#    #+#              #
#    Updated: 2017/09/27 11:28:17 by cchampou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

INC = includes minilibx_macos

SRC_DIR = src/

OBJ_DIR = obj/

SRC = main.c error_checks.c

OBJ = $(SRC:.c=.o)

CC = clang

CFLAGS = $(addprefix -I, $(INC))

all: $(NAME)

$(OBJ_DIR):
	mkdir -p obj

$(NAME): $(OBJ_DIR) $(addprefix $(OBJ_DIR),$(OBJ))
	$(CC) $(CFLAGS) $(addprefix $(OBJ_DIR),$(OBJ)) -o $@

$(OBJ_DIR)%.o: $(addprefix $(SRC_DIR), %.c)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
