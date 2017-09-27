# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchampou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 20:26:57 by cchampou          #+#    #+#              #
#    Updated: 2017/06/11 15:10:52 by cchampou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

C_FILES = 	ft_strlen.c		\
			ft_strtoupper.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isdigit.c	\
			ft_strcat.c		\
			ft_strncat.c	\
			ft_strlcat.c	\
			ft_strdup.c		\
			ft_strcpy.c		\
			ft_strncpy.c	\
			ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memccpy.c	\
			ft_memmove.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_strstr.c		\
			ft_strnstr.c	\
			ft_strcmp.c		\
			ft_strncmp.c	\
			ft_atoi.c		\
			ft_putchar.c	\
			ft_putstr.c		\
			ft_putnstr.c	\
			ft_memalloc.c	\
			ft_memdel.c		\
			ft_strnew.c		\
			ft_strdel.c		\
			ft_strclr.c		\
			ft_striter.c	\
			ft_striteri.c	\
			ft_strmap.c		\
			ft_strmapi.c	\
			ft_strequ.c		\
			ft_strnequ.c	\
			ft_strsub.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_strsplit.c	\
			ft_itoa.c		\
			ft_imtoa.c		\
			ft_uimtoa.c		\
			ft_ouimtoa.c	\
			ft_xuimtoa.c	\
			ft_putchar.c	\
			ft_putstr.c		\
			ft_putendl.c	\
			ft_putnbr.c		\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_lstnew.c		\
			ft_lstdelone.c	\
			ft_lstdel.c		\
			ft_lstadd.c		\
			ft_lstiter.c	\
			ft_lstmap.c		\
			ft_isupper.c	\
			ft_islower.c	\
			ft_str_is_alpha.c	\
			ft_str_is_numeric.c	\
			ft_str_is_printable.c	\
			ft_str_is_lowercase.c	\
			ft_str_is_uppercase.c	\
			ft_strndup.c			\
			ft_strlcpy.c			\
			ft_isblank.c			\
			ft_iscntrl.c			\
			ft_isgraph.c			\
			ft_isxdigit.c			\
			ft_strcapitalize.c		\
			ft_count_words.c

O_FILES = $(C_FILES:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(C_FILES) -Ilibft.h
	@ar rc $(NAME) $(O_FILES)

clean:
	@rm -rf $(O_FILES)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
