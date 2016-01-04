# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acioalai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/21 16:36:32 by acioalai          #+#    #+#              #
#    Updated: 2015/12/23 19:40:23 by mchindri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
SOURCE = main.c ft_read.c ft_check_map.c ft_create_map.c \
		 ft_putchar.c ft_strchr.c
O_FILE = main.o ft_read.o ft_check_map.o ft_create_map.o \
			ft_putchar.o ft_strchr.o
HEADER = fillit.h
TEST = a

$(NAME):
	@gcc -c $(FLAGS) $(SOURCE)
	@gcc -o $(NAME) $(O_FILE)
clean:
	@rm -f $(O_FILE)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

test: re
	./$(NAME) $(TEST)
