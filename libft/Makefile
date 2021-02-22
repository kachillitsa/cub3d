# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/30 22:57:47 by bjebedia          #+#    #+#              #
#    Updated: 2020/10/29 13:46:23 by bjebedia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LBFT_SRC = ft_atoi.c ft_itoa.c ft_itoa_base.c ft_nbrlen.c \
ft_free.c ft_free_2.c ft_free_3.c ft_free_4.c \
ft_nbrlenbase.c ft_nbrlenbase_ull.c ft_putchar_fd.c \
ft_putstr_fd.c ft_slltoa_base.c ft_strcmp.c ft_strchr.c \
ft_strdup.c ft_strjoin_f.c ft_strlcpy.c ft_strlen.c \
ft_strncmp.c ft_strnew.c ft_strnewfill.c ft_strrev.c \
ft_ulltoa_base_low.c ft_ulltoa_base_upp.c

LBFT_OBJ = $(LBFT_SRC:.c=.o)
INCLUDES = $(NAME:.a=.h)

SRC = $(LBFT_SRC)
OBJ = $(LBFT_OBJ)

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) compiled"

%.o: %.c $(INCLUDES)
	@gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
