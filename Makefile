# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 12:06:35 by ztouzri           #+#    #+#              #
#    Updated: 2021/06/28 16:29:31 by ztouzri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
NAME = push_swap
LIB = libft.a
SRCS = main.c parser.c error.c print.c push.c swap.c rotate.c reverse.c pileutils.c utils.c utils1.c groups.c free.c sort.c sort1.c
OBJS = $(SRCS:.c=.o)

.c.o:
	make -C libft/
	mv libft/$(LIB) .
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -Ilibft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) libft.a -o $(NAME) -Ilibft

all: $(NAME)

clean:
	make -C libft/ clean
	$(RM) $(LIB) $(OBJS)

fclean: clean
	make -C libft/ fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
