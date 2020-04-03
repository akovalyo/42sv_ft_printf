# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/01 21:26:34 by akovalyo          #+#    #+#              #
#    Updated: 2020/04/03 12:47:40 by akovalyo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
FLAGS=-Wall -Wextra -Werror -c
SRC=ft_printf.c \
		get.c \
		checker.c \
		print.c \
		analyse.c \
		helpers.c

OF = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	@make -C libft/ re
	@gcc $(FLAGS) -I ./libft/includes -c $(SRC)
	@ar rc $(NAME) $(OF) libft/*.o
	@ranlib $(NAME)

clean:
	@make -C libft/ clean
	@rm -f $(OF)

fclean: clean 
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

test:
	@gcc -g -o test $(SRC) -L ./libft -lft -I ./libft/includes
norm:
	@norminette -R CheckForbiddenSourceHeader $(SRC) libft.h