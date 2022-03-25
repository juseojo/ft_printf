# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongjch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 15:42:18 by seongjch          #+#    #+#              #
#    Updated: 2022/03/25 19:24:04 by seongjch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = let_print
SRC = ft_printf.c ft_strlen.c ft_strlcat.c ft_putchar_fd.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)


$(NAME): $(OBJ)
	ar -r $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
