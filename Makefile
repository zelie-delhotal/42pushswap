# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdelhota <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 15:41:48 by gdelhota          #+#    #+#              #
#    Updated: 2025/03/26 03:57:30 by gdelhota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c push_swap_utils.c ft_printf.c exec.c mini_push_swap.c
 
LIBS = libft/libft.a

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all:
	cd libft && $(MAKE) all clean
	$(CC) $(CFLAGS) $(SRCS) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJS) a.out

fclean: clean
	rm -f $(NAME) $(LIBS)

re: fclean all

.PHONY: all clean fclean re
