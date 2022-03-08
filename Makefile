# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 11:32:19 by nhirzel           #+#    #+#              #
#    Updated: 2022/02/23 13:58:00 by nhirzel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
CC		= gcc

FILES	= push_swap.c \
		  minilibft.c \
		  ft_split.c \
		  multicheek.c \
		  move.c \
		  move1.c \
		  move2.c \
		  move3.c \
		  algo.c \
		  algosmall.c \
		  before_swap.c \

OBJS 	= $(FILES:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -g -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
