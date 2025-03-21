# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdelhota <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 15:41:48 by gdelhota          #+#    #+#              #
#    Updated: 2025/03/20 00:25:50 by gdelhota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c push_swap_utils.c ft_printf.c exec.c pushswap_tester.c
 
LIBS = libft/libft.a

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#$(NAME):
#	$(CC) $(CFLAGS) -c $(SRCS) -o $(NAME)

all:
	cd libft && $(MAKE) all clean
	$(CC) $(CFLAGS) $(SRCS) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJS) $(OBJS) a.out

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all clean fclean re
